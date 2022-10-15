#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        if (N == 1) {
            std::cout << "1\n";
        } else if (N == 2) {
            std::cout << "-1\n";
        } else if (N == 3) {
            std::cout << "2 9 7\n4 6 3\n1 8 5\n";
        } else {
            std::vector a(N, std::vector<int>(N));
            int ptr = 1;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; j += 2) {
                    a[i][j] = ptr++;
                }
            }
            for (int i = 0; i < N; ++i) {
                for (int j = 1; j < N; j += 2) {
                    a[i][j] = ptr++;
                }
            }
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    std::cout << a[i][j] << "\n "[j + 1 < N];
                }
            }
        }
    }
    exit(0);
}