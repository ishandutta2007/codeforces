#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

constexpr int INF = 1 << 30;

int main() {
    int n;
    std::cin >> n;

    int evens = n / 2;
    int odds = n - evens;

    std::vector<int> xs(n);
    for (auto& x : xs) {
        std::cin >> x;
        if (x == 0) {
            x = -1;
            continue;
        }

        x %= 2;
        --(x == 0 ? evens : odds);
    }

    auto dp = vec(n + 1, vec(n + 1, vec(2, INF)));
    if (xs[0] < 0) {
        if (odds > 0) {
            dp[odds - 1][evens][1] = 0;
        }
        if (evens > 0) {
            dp[odds][evens - 1][0] = 0;
        }
    } else {
        dp[odds][evens][xs[0]] = 0;
    }

    for (int i = 1; i < n; ++i) {
        auto ndp = vec(n + 1, vec(n + 1, vec(2, INF)));
        int x = xs[i];
        for (int odd = 0; odd <= n; ++odd) {
            for (int even = 0; even <= n; ++even) {
                if (x < 0) {
                    if (odd > 0) {
                        ndp[odd - 1][even][1] =
                            std::min(
                                dp[odd][even][1],
                                dp[odd][even][0] + 1);
                    }
                    if (even > 0) {
                        ndp[odd][even - 1][0] =
                            std::min(
                                dp[odd][even][1] + 1,
                                dp[odd][even][0]);
                    }
                } else {
                    ndp[odd][even][x] = std::min(dp[odd][even][0] + (x != 0),
                                                 dp[odd][even][1] + (x != 1));
                }
            }
        }
        dp = ndp;
    }

    std::cout << std::min(dp[0][0][0], dp[0][0][1]) << std::endl;
    return 0;
}