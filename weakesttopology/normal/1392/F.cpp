#include <iostream>
#include <vector>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<long long> h(N);
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        std::cin >> h[i];
        sum += h[i];
    }
    for (int i = 0; i + 1 < N; ++i) {
        auto f = [&](long long x) {
            return 1LL * N * x - 1LL * i * (i + 1) / 2 + 1LL * (N - i - 1) * (N - i - 2) / 2;
        };
        long long x = (sum + 1LL * i * (i + 1) / 2 - 1LL * (N - i - 1) * (N - i - 2) / 2) / N;
        if (f(x) == sum) {
            for (int j = i; j >= 0; --j) {
                h[j] = x - (i - j);
            }
            for (int j = i + 1; j < N; ++j) {
                h[j] = x + (j - i - 1);
            }
            break;
        }
    }
    if (long long x = (sum - 1LL * N * (N - 1) / 2); x % N == 0) {
        x /= N;
        for (int i = 0; i < N; ++i) {
            h[i] = x + i;
        }
    }
    for (int i = 0; i < N; ++i) {
        std::cout << h[i] << "\n "[i + 1 < N];
    }
    exit(0);
}