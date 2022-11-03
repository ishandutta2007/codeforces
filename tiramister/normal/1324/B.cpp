#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    bool ok = false;
    std::vector<int> prev(n, -1);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        --x;

        if (prev[x] == -1) {
            prev[x] = i;
        } else if (i - prev[x] > 1) {
            ok = true;
        }
    }

    std::cout << (ok ? "YES" : "NO") << "\n";
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