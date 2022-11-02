#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    int c = 0;
    while (xs[c] != n) ++c;

    for (int i = c; i - 1 >= 0; --i) {
        if (xs[i - 1] > xs[i]) {
            std::cout << "NO\n";
            return;
        }
    }
    for (int i = c; i + 1 < n; ++i) {
        if (xs[i] < xs[i + 1]) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}