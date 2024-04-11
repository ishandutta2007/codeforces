#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        long double y[2];
        for (int t : {0, 1}) {
            int x, p;
            std::cin >> x >> p;
            while (x % 10 == 0) {
                x /= 10;
                ++p;
            }
            y[t] = log10l(x) + p;
        }
        std::cout << (y[0] < y[1] ? '<' : y[0] == y[1] ? '=' : '>') << '\n';
    }
    exit(0);
}