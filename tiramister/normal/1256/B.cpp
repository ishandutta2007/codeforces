#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    std::vector<bool> used(n - 1, false);
    for (int x = 1; x <= n; ++x) {
        int i = std::find(xs.begin(), xs.end(), x) - xs.begin() - 1;
        while (i >= 0 && xs[i] > xs[i + 1] && !used[i]) {
            std::swap(xs[i], xs[i + 1]);
            used[i] = true;
            --i;
        }
    }

    for (auto x : xs) std::cout << x << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}