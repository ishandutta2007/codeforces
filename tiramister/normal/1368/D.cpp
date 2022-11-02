#include <iostream>
#include <vector>

using lint = long long;
constexpr int X = 20;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> cnt(X, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        for (int j = 0; j < X; ++j) {
            cnt[j] += ((x >> j) & 1);
        }
    }

    lint ans = 0;
    while (n--) {
        lint x = 0;
        for (int j = 0; j < X; ++j) {
            if (cnt[j] == 0) continue;
            x += (1 << j);
            --cnt[j];
        }
        ans += x * x;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}