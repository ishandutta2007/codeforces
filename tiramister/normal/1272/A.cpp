#include <iostream>

void solve() {
    int max = 0, min = 1 << 30;
    for (int i = 0; i < 3; ++i) {
        int x;
        std::cin >> x;
        max = std::max(max, x);
        min = std::min(min, x);
    }

    std::cout << std::max(max - min - 2, 0) * 2 << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}