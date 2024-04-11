#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    int m = 0;
    while (n + 1 > (1LL << (m + 1))) ++m;

    std::vector<int> ans(m + 1);
    for (int i = 0; i <= m; ++i) {
        ans[i] = std::min(1 << i, n / (m - i + 1));
        n -= ans[i];
    }

    std::cout << m << "\n";
    for (int i = 0; i < m; ++i) {
        std::cout << ans[i + 1] - ans[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}