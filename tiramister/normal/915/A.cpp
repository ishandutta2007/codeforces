#include <iostream>

void solve() {
    int n, k;
    std::cin >> n >> k;

    int ans = k;
    while (n--) {
        int x;
        std::cin >> x;
        if (k % x == 0) ans = std::min(ans, k / x);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}