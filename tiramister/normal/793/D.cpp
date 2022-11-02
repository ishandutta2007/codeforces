#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

constexpr int INF = 1 << 29;

void solve() {
    int n, k;
    std::cin >> n >> k;

    auto adj = vec(n, vec(n, INF));
    {
        int m;
        std::cin >> m;
        while (m--) {
            int u, v, c;
            std::cin >> u >> v >> c;
            --u, --v;
            if (u != v) adj[u][v] = std::min(adj[u][v], c);
        }
    }

    auto dp = vec(n, vec(n, vec(2, 0)));
    auto ndp = dp;

    --k;
    while (k--) {
        for (int pl = 0; pl < n; ++pl) {
            for (int pr = pl; pr < n; ++pr) {
                for (int s = 0; s < 2; ++s) {
                    ndp[pl][pr][s] = INF;
                }
            }
        }

        for (int pl = 0; pl < n; ++pl) {
            for (int pr = pl; pr < n; ++pr) {
                {
                    int s = 0, i = pl;
                    for (int j = pl + 1; j <= pr; ++j) {
                        {
                            // to right
                            auto nl = j,
                                 nr = pr,
                                 ns = 0;

                            auto nd = dp[pl][pr][s] + adj[i][j];
                            ndp[nl][nr][ns] = std::min(ndp[nl][nr][ns], nd);
                        }
                        {
                            // to left
                            auto nl = pl + 1,
                                 nr = j,
                                 ns = 1;

                            auto nd = dp[pl][pr][s] + adj[i][j];
                            ndp[nl][nr][ns] = std::min(ndp[nl][nr][ns], nd);
                        }
                    }
                }

                {
                    int s = 1, i = pr;
                    for (int j = pl; j <= pr - 1; ++j) {
                        {
                            // to right
                            auto nl = j,
                                 nr = pr - 1,
                                 ns = 0;

                            auto nd = dp[pl][pr][s] + adj[i][j];
                            ndp[nl][nr][ns] = std::min(ndp[nl][nr][ns], nd);
                        }
                        {
                            // to left
                            auto nl = pl,
                                 nr = j,
                                 ns = 1;

                            auto nd = dp[pl][pr][s] + adj[i][j];
                            ndp[nl][nr][ns] = std::min(ndp[nl][nr][ns], nd);
                        }
                    }
                }
            }
        }

        std::swap(dp, ndp);
    }

    int ans = INF;
    for (int pl = 0; pl < n; ++pl) {
        for (int pr = pl; pr < n; ++pr) {
            for (int s = 0; s < 2; ++s) {
                ans = std::min(ans, dp[pl][pr][s]);
            }
        }
    }

    std::cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}