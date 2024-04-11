#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::map<std::string, std::vector<std::array<int, 2>>> mp;
    mp["?"].resize(M);
    for (int j = 0; j < M; ++j) {
        mp["?"][j][1] = 1;
    }
    for (int i = 0; i < N; ++i) {
        std::string var, junk;
        std::cin >> var >> junk;
        std::string a;
        std::cin >> a;
        mp[var].resize(M);
        if (std::isdigit(a[0])) {
            for (int j = 0; j < M; ++j) {
                mp[var][j][0] = mp[var][j][1] = a[j] - '0';
            }
        } else {
            std::string op, b;
            std::cin >> op >> b;
            auto f = [&](int x, int y) {
                return op == "AND" ? x & y : op == "OR" ? x | y : x ^ y;
            };
            for (int j = 0; j < M; ++j) {
                for (int t : {0, 1}) {
                    mp[var][j][t] = f(mp[a][j][t], mp[b][j][t]);
                }
            }
        }
    }
    std::vector<std::array<int, 2>> sum(M);
    for (auto [k, v] : mp) {
        if (k == "?") continue;
        for (int j = 0; j < M; ++j) {
            for (int t : {0, 1}) {
                sum[j][t] += v[j][t];
            }
        }
    }
    std::vector<int> min(M), max(M);
    for (int j = 0; j < M; ++j) {
        min[j] = sum[j][0] <= sum[j][1] ? 0 : 1;
        max[j] = sum[j][0] >= sum[j][1] ? 0 : 1;
    }
    for (int j = 0; j < M; ++j) {
        std::cout << min[j];
    }
    std::cout << '\n';
    for (int j = 0; j < M; ++j) {
        std::cout << max[j];
    }
    std::cout << '\n';
    exit(0);
}