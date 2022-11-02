#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    int win = 0;
    int i;
    for (i = 0; i < n; ++i) {
        if (xs[i] == 1) {
            win = 1 - win;
        } else {
            break;
        }
    }

    std::cout << ((i < n) == (win == 0) ? "First" : "Second")
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