#include <iostream>
#include <vector>
#include <string>

void solve() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> cnt(n * 2 + 1, 0);
    int h = n;
    for (int i = 0; i < n; ++i) {
        ++cnt[h];

        char c;
        std::cin >> c;
        h += (c == '0' ? 1 : -1);
    }
    int d = h - n;

    if (d == 0) {
        std::cout << (-n <= x && x <= n && cnt[x + n] > 0 ? -1 : 0)
                  << std::endl;
        return;
    }

    int ans = 0;
    for (int k = -n; k <= n; ++k) {
        int c = cnt[k + n];
        int diff = x - k;
        if (diff % d == 0 && diff / d >= 0) ans += c;
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