#include <iostream>
#include <set>

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::set<int> s;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        s.insert(x);
    }

    if ((int)s.size() > k) {
        std::cout << "-1\n";
        return;
    }

    for (int x = 1; x <= n && (int)s.size() < k; ++x) {
        s.insert(x);
    }

    std::cout << k * n << "\n";
    for (int i = 0; i < n; ++i) {
        for (auto x : s) {
            std::cout << x << " ";
        }
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