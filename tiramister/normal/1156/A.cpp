#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (xs[i] != 1 && xs[i + 1] != 1) {
            std::cout << "Infinite\n";
            return;
        }

        int c = std::max(xs[i], xs[i + 1]);
        ans += c + 1;
    }

    for (int i = 0; i + 2 < n; ++i) {
        if (xs[i] == 3 && xs[i + 1] == 1 && xs[i + 2] == 2) --ans;
    }

    std::cout << "Finite\n"
              << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}