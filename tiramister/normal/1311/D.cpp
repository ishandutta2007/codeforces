#include <iostream>
#include <algorithm>
#include <cmath>

constexpr int X = 20000;

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int px = -X, py = -X, pz = -X;

    for (int y = 1; y <= X; ++y) {
        int x = -X;
        for (int p = 1; p * p <= y; ++p) {
            if (y % p != 0) continue;

            int xi = p;
            if (std::abs(a - xi) < std::abs(a - x)) x = xi;
            xi = y / p;
            if (std::abs(a - xi) < std::abs(a - x)) x = xi;
        }

        int q = c / y;
        int z1 = q * y, z2 = (q + 1) * y;
        int z = (std::abs(c - z1) < std::abs(c - z2) ? z1 : z2);

        if (std::abs(x - a) + std::abs(y - b) + std::abs(z - c) <
            std::abs(px - a) + std::abs(py - b) + std::abs(pz - c)) {
            px = x;
            py = y;
            pz = z;
        }
    }

    std::cout << std::abs(px - a) + std::abs(py - b) + std::abs(pz - c)
              << std::endl
              << px << " " << py << " " << pz
              << std::endl;
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