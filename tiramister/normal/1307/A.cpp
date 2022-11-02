#include <iostream>

void solve() {
    int n, d;
    std::cin >> n >> d;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        while (x--) {
            if (d >= i) {
                ++ans;
                d -= i;
            }
        }
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