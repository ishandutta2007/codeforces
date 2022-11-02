#include <iostream>

void solve() {
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}