#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    if (n == 1) {
        std::cout << -1 << "\n";
        return;
    }

    std::cout << 5;
    --n;
    while (n--) std::cout << 9;
    std::cout << "\n";
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