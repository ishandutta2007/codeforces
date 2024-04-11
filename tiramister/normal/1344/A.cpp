#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> cnt(n, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        a %= n;
        if (a < 0) a += n;
        ++cnt[(i + a) % n];
    }

    std::cout << (*std::max_element(cnt.begin(), cnt.end()) == 1 ? "YES" : "NO")
              << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}