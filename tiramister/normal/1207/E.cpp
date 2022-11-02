#include <iostream>

void solve() {
    int ans = 0;

    {
        std::cout << "?";
        for (int i = 1; i <= 100; ++i) {
            std::cout << " " << i;
        }
        std::cout << std::endl;

        int x;
        std::cin >> x;
        ans += ((x >> 7) << 7);
    }

    {
        std::cout << "?";
        for (int i = 1; i <= 100; ++i) {
            std::cout << " " << i * (1 << 7);
        }
        std::cout << std::endl;

        int x;
        std::cin >> x;
        ans += x - ((x >> 7) << 7);
    }

    std::cout << "! " << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}