#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, K;
    std::cin >> N >> K;
    int64_t r = 0, sum = 0;
    for (int i = 0; i < N; ++i) {
        int64_t a;
        std::cin >> a;
        int64_t d = sum - r * (N - (i - r) - (r + 1)) * a;
        if (d >= K) {
            sum += a * r;
            ++r;
        } else {
            std::cout << i + 1 << '\n';
        }
    }
    exit(0);
}