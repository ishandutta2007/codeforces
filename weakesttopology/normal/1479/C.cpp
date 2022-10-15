#include <iostream>
#include <vector>
#include <queue>
constexpr int K = 20;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int L, R;
    std::cin >> L >> R;
    int N = K + 2;
    std::vector<std::vector<std::pair<int, int>>> E(N);
    int len = R - L;
    for (int k = 0; k < K; ++k) {
        for (int v = 0; v < k; ++v) {
            E[k].emplace_back(v, 1 << v);
        }
        if (len >> k & 1) {
            int x = len;
            while (true) {
                int lsb = x & -x;
                x -= lsb;
                if (lsb == (1 << k)) break;
            }
            E[K].emplace_back(k, L + x);
        }
    }
    for (int k = 0; k < K; ++k) {
        E[k].emplace_back(K + 1, 1);
    }
    E[K].emplace_back(K + 1, L);
    int M = 0;
    std::vector<int> d(N);
    for (int u = 0; u < N; ++u) {
        for (auto [v, w] : E[u]) {
            ++M;
            ++d[v];
        }
    }
    std::queue<int> q;
    q.push(K);
    for (int u = 0; u < N; ++u) {
        if (u == K) continue;
        if (d[u] == 0) {
            q.push(u);
        }
    }
    std::vector<int> label(N);
    int timer = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        label[u] = timer++;
        for (auto [v, w] : E[u]) {
            if (--d[v] == 0) {
                q.push(v);
            }
        }
    }
    std::cout << "YES\n" << N << ' ' << M << '\n';
    for (int u = 0; u < N; ++u) {
        for (auto [v, w] : E[u]) {
            std::cout << label[u] + 1 << ' ' << label[v] + 1 << ' ' << w << '\n';
        }
    }
    return 0;
}