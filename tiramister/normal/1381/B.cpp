#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> ms;
    {
        int max = 0, m = 0;
        for (int i = 0; i < n * 2; ++i) {
            int x;
            std::cin >> x;

            if (x > max) {
                max = x;
                ms.push_back(m);
                m = 0;
            }
            ++m;
        }
        ms.push_back(m);
    }

    std::vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (auto m : ms) {
        for (int i = n; i >= m; --i) {
            if (dp[i - m]) dp[i] = true;
        }
    }

    std::cout << (dp[n] ? "YES" : "NO") << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}