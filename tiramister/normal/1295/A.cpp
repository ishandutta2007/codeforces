#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    while (n > 0) {
        if (n % 2 == 1) {
            std::cout << 7;
            n -= 3;
        } else {
            std::cout << 1;
            n -= 2;
        }
    }
    std::cout << std::endl;
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