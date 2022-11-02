#include <iostream>

void solve() {
    int a, b;
    std::cin >> a >> b;

    int ans;
    if (a == b) {
        ans = 0;
    } else if ((a < b && (b - a) % 2 != 0) ||
               ((a > b) && (a - b) % 2 == 0)) {
        ans = 1;
    } else {
        ans = 2;
    }

    std::cout << ans << std::endl;
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