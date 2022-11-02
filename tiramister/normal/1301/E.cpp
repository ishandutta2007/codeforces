#include <iostream>
#include <vector>
#include <string>

constexpr int K = 250;
int cnt[K + 1][501][501];

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::string> ss(n);
    for (auto& s : ss) std::cin >> s;

    for (int sx = 0; sx < n; ++sx) {
        for (int sy = 0; sy < m; ++sy) {
            for (int k = 0;; ++k) {
                bool judge = true;

                for (int x = sx - k; x <= sx + k + 1; ++x) {
                    for (int y = sy - k; y <= sy + k + 1; ++y) {
                        if (x < 0 || n <= x || y < 0 || m <= y) {
                            judge = false;
                            break;
                        }

                        char c;
                        if (x <= sx && y <= sy) {
                            c = 'R';
                        } else if (x > sx && y <= sy) {
                            c = 'Y';
                        } else if (x <= sx && y > sy) {
                            c = 'G';
                        } else {
                            c = 'B';
                        }

                        if (ss[x][y] != c) {
                            judge = false;
                            break;
                        }
                    }
                    if (!judge) break;
                }
                if (!judge) break;
                cnt[k + 1][sx - k + 1][sy - k + 1] = 1;
            }
        }
    }

    for (int k = 0; k <= K; ++k) {
        for (int x = 0; x <= n; ++x) {
            for (int y = 1; y <= m; ++y) {
                cnt[k][x][y] += cnt[k][x][y - 1];
            }
        }

        for (int x = 1; x <= n; ++x) {
            for (int y = 0; y <= m; ++y) {
                cnt[k][x][y] += cnt[k][x - 1][y];
            }
        }
    }

    while (q--) {
        int lx, ly, rx, ry;
        std::cin >> lx >> ly >> rx >> ry;
        --lx, --ly;

        int ok = 0, ng = K + 1;
        while (ng - ok > 1) {
            int k = (ok + ng) / 2;
            int nrx = rx - (k * 2 - 1),
                nry = ry - (k * 2 - 1);
            if (nrx <= lx || nry <= ly) {
                ng = k;
                continue;
            }

            int c = cnt[k][nrx][nry] - cnt[k][nrx][ly] -
                    cnt[k][lx][nry] + cnt[k][lx][ly];
            if (c > 0) {
                ok = k;
            } else {
                ng = k;
            }
        }
        std::cout << ok * ok * 4 << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}