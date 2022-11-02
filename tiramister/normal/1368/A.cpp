#include <iostream>

void solve() {
    int a, b, n;
    std::cin >> a >> b >> n;

    if (a < b) std::swap(a, b);
    int ans = 0;
    while (a <= n) {
        int s = a + b;
        b = a;
        a = s;
        ++ans;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}