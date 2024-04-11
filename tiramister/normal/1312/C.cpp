#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    int n;
    lint k;
    std::cin >> n >> k;

    std::vector<bool> chosen(60, false);
    bool ok = true;
    while (n--) {
        lint x;
        std::cin >> x;
        for (int i = 0; i < 60; ++i) {
            lint d = x % k;
            x /= k;

            if (d == 0) continue;
            if (d > 1 || chosen[i]) ok = false;
            chosen[i] = true;
        }
    }

    std::cout << (ok ? "YES" : "NO") << std::endl;
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