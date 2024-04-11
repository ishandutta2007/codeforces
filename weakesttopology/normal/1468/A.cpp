#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stack>
#include <cassert>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
        }
        a.insert(a.begin(), 0);
        ++N;
        std::stack<int> stk;
        std::vector<std::vector<int>> E(N);
        for (int i = N - 1; i >= 0; --i) {
            while (!stk.empty() && a[stk.top()] <= a[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                E[stk.top()].push_back(i);
            }
            stk.push(i);
        }
        std::vector<int> dp(N + 1, std::numeric_limits<int>::max()), s(N);
        dp[0] = std::numeric_limits<int>::min();
        for (int i = 0; i < N; ++i) {
            s[i] = std::upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[s[i]] = a[i];
            for (auto j : E[i]) {
                dp[s[j] + 1] = std::min(dp[s[j] + 1], a[j]);
            }
            //assert(std::is_sorted(dp.begin(), dp.end()));
        }
        int l = 0;
        while (l < N && dp[l + 1] < std::numeric_limits<int>::max()) ++l;
        std::cout << l - 1 << '\n';
    }
    exit(0);
}