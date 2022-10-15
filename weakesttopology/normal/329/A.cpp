#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<std::string> g(N);
    bool good = true;
    std::vector<std::pair<int, int>> ops;
    for (int i = 0; i < N; ++i) {
        std::cin >> g[i];
        auto iter = std::find(g[i].begin(), g[i].end(), '.');
        if (good && iter != g[i].end()) {
            ops.emplace_back(i, iter - g[i].begin());
        } else {
            ops.clear();
            good = false;
        }
    }
    if (!good) {
        for (int j = 0; j < N; ++j) {
            bool found = false;
            for (int i = 0; i < N; ++i) {
                if (g[i][j] == '.') {
                    found = true;
                    ops.emplace_back(i, j);
                    break;
                }
            }
            if (!found) {
                std::cout << "-1\n";
                exit(0);
            }
        }
    }
    for (auto [i, j] : ops) {
        std::cout << i + 1 << ' ' << j + 1 << '\n';
    }
    exit(0);
}