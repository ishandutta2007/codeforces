#include <iostream>
#include <vector>
#include <string>

void solve() {
    int n, m, q;
    std::string s, t;
    std::cin >> n >> m >> q >> s >> t;

    if (n < m) {
        while (q--) std::cout << 0 << "\n";
        return;
    }

    std::vector<int> acc(n - m + 2, 0);
    for (int i = 0; i + m <= n; ++i) {
        acc[i + 1] = acc[i];
        if (s.substr(i, m) == t) ++acc[i + 1];
    }

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        r -= m - 1;

        std::cout << (r < l ? 0 : acc[r] - acc[l - 1]) << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}