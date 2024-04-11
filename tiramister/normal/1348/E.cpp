#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

using lint = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<bool> dp(k, false);
    dp[0] = true;
    std::vector<bool> ndp = dp;

    lint sum = 0;
    while (n--) {
        lint psum = sum;

        lint a, b;
        std::cin >> a >> b;
        sum += a + b;

        std::fill(ndp.begin(), ndp.end(), false);

        for (lint s = 0; s < k; ++s) {
            if (!dp[s]) continue;

            lint t = (psum - s) % k;
            if (t < 0) t += k;

            lint ds = 0;
            lint ns = s;

            lint nt = (sum - ns) % k;
            if (nt < 0) nt += k;
            lint dt = (nt - t + k) % k;

            for (int i = 0; i < k; ++i) {
                if (ds <= a && dt <= b) ndp[ns] = true;

                ++ds;
                if (++ns >= k) ns -= k;

                if (--dt < 0) dt += k;
                if (--nt < 0) nt += k;
            }
        }

        dp = ndp;
    }

    lint ans = 0;
    for (lint s = 0; s < k; ++s) {
        if (!dp[s]) continue;

        lint t = (sum - s) % k;
        if (t < 0) t += k;
        ans = std::max(ans, sum - (s + t));
    }

    std::cout << ans / k << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}