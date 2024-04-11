#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> cnt(2, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        ++cnt[x % 2];
    }

    for (int i = 0; i < 2; ++i) {
        if (cnt[i] == n) {
            std::cout << "YES" << std::endl;
            return;
        }
    }
    std::cout << "NO" << std::endl;
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