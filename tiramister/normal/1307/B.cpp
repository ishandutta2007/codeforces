#include <iostream>

void solve() {
    int n, x;
    std::cin >> n >> x;

    int max = 0;
    bool just = false;
    while (n--) {
        int a;
        std::cin >> a;
        max = std::max(max, a);
        if (x == a) just = true;
    }

    int ans = (x + max - 1) / max;
    if (!just) ans = std::max(ans, 2);
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