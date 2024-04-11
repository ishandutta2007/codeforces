#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, M;
        std::cin >> N >> M;
        std::vector<bool> matched(3 * N);
        std::vector<int> matching;
        for (int j = 0; j < M; ++j) {
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            if (!matched[u] && !matched[v]) {
                matched[u] = true;
                matched[v] = true;
                matching.push_back(j);
            }
        }
        if (matching.size() >= N) {
            std::cout << "Matching\n";
            for (int i = 0; i < N; ++i) {
                std::cout << matching[i] + 1 << "\n "[i + 1 < N];
            }
        } else {
            std::cout << "IndSet\n";
            for (int u = 0, cnt = 0; u < 3 * N && cnt < N; ++u) {
                if (!matched[u]) {
                    std::cout << u + 1 << "\n "[cnt + 1 < N];
                    ++cnt;
                }
            }
        }
    }
    exit(0);
}