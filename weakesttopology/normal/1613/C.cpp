#include <bits/stdc++.h>
const int64_t inf = std::numeric_limits<int64_t>::max();
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        int64_t H;
        std::cin >> N >> H;
        std::vector<int64_t> a(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
        }
        a.push_back(inf);
        int64_t L = 0, R = inf / 2;
        while (L + 1 < R) {
            int64_t k = L + (R - L) / 2, sum = 0;
            for (int i = 0; i < N && sum < H; ++i) {
                sum += std::min(a[i + 1], a[i] + k) - a[i];
            }
            sum >= H ? R = k : L = k;
        }
        std::cout << R << '\n';
    }
    exit(0);
}