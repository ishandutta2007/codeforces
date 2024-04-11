#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    int p;
    std::cin >> p;

    bool same = true;
    for (int i = 0; i < n - 1; ++i) {
        int x;
        std::cin >> x;
        if (x != p) same = false;
        p = x;
    }

    std::cout << (same ? n : 1) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}