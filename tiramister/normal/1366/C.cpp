#include <iostream>
#include <vector>

void solve() {
    int n, m;
    std::cin >> n >> m;
    int l = n + m - 2;

    std::vector<int> zs(l + 1, 0), os(l + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c;
            std::cin >> c;

            if (c == 0) {
                ++zs[i + j];
            } else {
                ++os[i + j];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < l - i; ++i) {
        int z = zs[i] + zs[l - i];
        int o = os[i] + os[l - i];
        ans += std::min(z, o);
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