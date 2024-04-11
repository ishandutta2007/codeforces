#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        std::vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
        }
        std::iter_swap(a.begin(), std::min_element(a.begin(), a.end()));
        for (int i = 1; i < N / 2 + 1; ++i) {
            std::cout << a[i] << ' ' << a[0] << '\n';
        }
    }
    exit(0);
}