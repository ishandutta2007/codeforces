// HELLO DIV. 2
#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;
        for (int a = 2; a <= N + 1; ++a) {
            std::cout << a << "\n "[a < N];
        }
    }
    exit(0);
}