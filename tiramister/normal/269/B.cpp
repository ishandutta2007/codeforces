#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> dp(m, 0);
    while (n--) {
        int k;
        {
            double x;
            std::cin >> k >> x;
            --k;
        }

        for (int i = 0; i < m; ++i) {
            if (i != k) ++dp[i];
        }
        for (int i = 1; i < m; ++i) {
            dp[i] = std::min(dp[i], dp[i - 1]);
        }
    }

    std::cout << dp.back() << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}