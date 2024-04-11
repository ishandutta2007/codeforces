#include <iostream>

void solve() {
    int n, d;
    std::cin >> n >> d;

    int pd = d + 1;
    for (int x = 0; x <= n; ++x) {
        int nd = (d + x) / (x + 1);

        if (x + nd <= n) {
            std::cout << "YES" << std::endl;
            return;
        }

        if (nd == pd) break;
        pd = nd;
    }
    std::cout << "NO" << std::endl;
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