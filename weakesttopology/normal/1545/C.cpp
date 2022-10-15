#include "bits/stdc++.h"
constexpr int mod = 998244353;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::vector<std::vector<int>> p(2 * N);
        for (int i = 0; i < 2 * N; ++i) {
            p[i].resize(N);
            for (int j = 0; j < N; ++j) {
                std::cin >> p[i][j];
                --p[i][j];
            }
        }
        std::vector<bool> dead(2 * N);
        auto check_edge = [&](int i, int j) {
            for (int k = 0; k < N; ++k) {
                if (p[i][k] == p[j][k]) {
                    return true;
                }
            }
            return false;
        };
        std::vector<int> I;
        while (true) {
            bool converged = true;
            for (int j = 0; j < N; ++j) {
                std::vector<int> cnt(N);
                for (int i = 0; i < 2 * N; ++i) {
                    if (dead[i]) continue;
                    ++cnt[p[i][j]];
                }
                for (int i = 0; i < 2 * N; ++i) {
                    if (dead[i]) continue;
                    if (cnt[p[i][j]] == 1) {
                        converged = false;
                        I.push_back(i);
                        for (int k = 0; k < 2 * N; ++k) {
                            if (check_edge(i, k)) {
                                dead[k] = true;
                            }
                        }
                    }
                }
            }
            if (converged) break;
        }
        auto dfs = [&](auto& self, int i, bool take) -> void {
            dead[i] = true;
            if (take) {
                I.push_back(i);
            }
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < 2 * N; ++k) {
                    if (p[i][j] == p[k][j] && !dead[k]) {
                        self(self, k, !take);
                    }
                }
            }
        };
        int cnt = 1;
        for (int i = 0; i < 2 * N; ++i) {
            if (!dead[i]) {
                dfs(dfs, i, true);
                cnt = 2 * cnt % mod;
            }
        }
        assert(I.size() == N);
        std::cout << cnt << '\n';
        for (int i = 0; i < N; ++i) {
            std::cout << I[i] + 1 << "\n "[i + 1 < N];
        }
    }
    exit(0);
}