#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> deg(N), p(N);
    for (int u = 1; u < N; ++u) {
        std::cin >> p[u];
        --p[u];
        ++deg[p[u]];
    }
    std::vector<int> cnt(N);
    for (int u = N - 1; u >= 0; --u) {
        if (deg[u] == 0) {
            ++cnt[p[u]];
        } else if (cnt[u] < 3) {
            std::cout << "No\n";
            exit(0);
        }
    }
    std::cout << "Yes\n";
    exit(0);
}