#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

// https://leetcode.com/problems/range-sum-of-bst/

// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

#include <typeinfo>

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

//   template<typename T>
    void inorder(TreeNode *r, function<void (int)> fptr) {
        if (!r) return;
        inorder(r->left, fptr);
        fptr(r->val);
        inorder(r->right, fptr);
    }

    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        int sum = 0;
        auto lam = [&sum, L, R](int i) {
            if (i >= L && i <= R)
                sum += i;
        };
        inorder(root, lam);
        return sum;
    }
};

void test1() {
    auto t1 = new TreeNode("10,5,15,3,7,null,18");
    cout << t1 << endl;
    cout << " ? " << Solution().rangeSumBST(t1, 7, 15) << endl;
}

void test2() {

}

void test3() {

}