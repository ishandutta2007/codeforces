#include <bits/stdc++.h>
constexpr int amax = 5000, K = 13;
std::vector<int> q[amax + 1];
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> q(amax + 1, {0});
    std::vector<int> best(1 << K, amax + 1);
    best[0] = -1;
    for (int i = 0; i < N; ++i) {
        int a;
        std::cin >> a;
        for (auto x : q[a]) {
            int y = x ^ a;
            if (a < best[y]) {
                for (int b = a + 1; b < best[y]; ++b) {
                    q[b].push_back(y);
                }
                best[y] = a;
            }
        }
        q[a].clear();
    }
    std::vector<int> xs;
    for (int x = 0; x < (1 << K); ++x) {
        if (best[x] <= amax) {
            xs.push_back(x);
        }
    }
    int k = xs.size();
    std::cout << k << '\n';
    for (int j = 0; j < k; ++j) {
        std::cout << xs[j] << "\n "[j + 1 < k];
    }
    exit(0);
}