#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        int64_t sum = 0, max = 0, mult = 1;
        for (int i = 0; i < N; ++i) {
            int64_t a;
            std::cin >> a;
            while (a % 2 == 0) {
                a /= 2;
                mult *= 2;
            }
            if (a > max) {
                std::swap(a, max);
            }
            sum += a;
        }
        sum += mult * max;
        std::cout << sum << '\n';
    }
    exit(0);
}