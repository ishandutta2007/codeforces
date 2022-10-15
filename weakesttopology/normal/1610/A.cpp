#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, M;
        std::cin >> N >> M;
        int k;
        if (N == 1 && M == 1) {
            k = 0;
        } else if (N == 1 || M == 1) {
            k = 1;
        } else {
            k = 2;
        }
        std::cout << k << '\n';
    }
    exit(0);
}