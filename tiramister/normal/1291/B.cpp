#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    int l = 0;
    while (true) {
        if (l == n || xs[l] < l) break;
        ++l;
    }

    int r = n - 1;
    while (true) {
        if (r < 0 || xs[r] < n - r - 1) break;
        --r;
    }

    std::cout << (l - r > 1 ? "Yes" : "No") << std::endl;
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