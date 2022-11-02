#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    for (int i = 0; i < n; ++i) {
        int l = -1;
        for (int j = i - 1; j >= 0; --j) {
            if (xs[j] < xs[i]) {
                l = j;
                break;
            }
        }

        int r = -1;
        for (int j = i + 1; j < n; ++j) {
            if (xs[j] < xs[i]) {
                r = j;
                break;
            }
        }

        if (l != -1 && r != -1) {
            std::cout << "YES\n"
                      << l + 1 << " " << i + 1 << " " << r + 1
                      << "\n";
            return;
        }
    }

    std::cout << "NO\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}