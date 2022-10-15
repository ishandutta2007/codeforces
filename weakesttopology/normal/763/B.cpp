#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::cout << "YES\n";
    for (int i = 0; i < N; ++i) {
        int x, y;
        std::cin >> x >> y >> x >> y;
        int color = (x & 1) << 1 | y & 1;
        std::cout << color + 1 << '\n';
    }
    exit(0);
}