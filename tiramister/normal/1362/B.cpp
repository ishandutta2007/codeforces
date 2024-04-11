#include <iostream>
#include <vector>

constexpr int X = 1 << 10;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> cnt(X, 0);
    while (n--) {
        int x;
        std::cin >> x;
        ++cnt[x];
    }

    for (int x = 1; x < X; ++x) {
        bool judge = true;
        for (int y = 0; y < X; ++y) {
            if (cnt[x ^ y] != cnt[y]) judge = false;
        }

        if (judge) {
            std::cout << x << "\n";
            return;
        }
    }

    std::cout << "-1\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}