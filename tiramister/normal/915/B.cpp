#include <iostream>

void solve() {
    int n, x, l, r;
    std::cin >> n >> x >> l >> r;

    if (l == 1) {
        if (r == n) {
            std::cout << "0\n";
        } else {
            std::cout << std::abs(r - x) + 1 << "\n";
        }
    } else if (r == n) {
        std::cout << std::abs(l - x) + 1 << "\n";
    } else {
        std::cout << std::min(std::abs(l - x), std::abs(r - x)) + (r - l) + 2 << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}