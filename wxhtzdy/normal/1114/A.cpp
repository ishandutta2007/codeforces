#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y, z;
    std::cin >> x >> y >> z;

    int a, b, c;
    std::cin >> a >> b >> c;

    if (a < x) return std::cout << "NO\n", 0;
    a -= x;
    if (a + b < y) return std::cout << "NO\n", 0;
    if (a + b - y + c < z) return std::cout << "NO\n", 0;

    std::cout << "YES\n";

    return 0;
}