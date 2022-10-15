#include "bits/stdc++.h"
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        int sum = 0, odd = -1;
        for (int i = 0; i < N; ++i) {
            int a;
            std::cin >> a;
            sum += a;
            if (a % 2) {
                odd = i;
            }
        }
        bool good = false;
        for (int y = 2; y < sum; ++y) {
            if (sum % y == 0) {
                good = true;
                break;
            }
        }
        int x = N - !good;
        std::cout << x << '\n';
        for (int i = 0; i < N; ++i) {
            if (!good && odd == i) continue;
            std::cout << i + 1 << ' ';
        }
        std::cout << '\n';
    }
    exit(0);
}