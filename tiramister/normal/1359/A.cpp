#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> cnt(k, 0);
    for (int i = 0; i < n / k && m > 0; ++i) {
        ++cnt[0];
        --m;
    }

    for (int i = 0; i < n / k && m > 0; ++i) {
        for (int j = 1; j < k && m > 0; ++j) {
            ++cnt[j];
            --m;
        }
    }

    std::cout << cnt[0] - cnt[1] << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}