#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int x = 1, y = n;

    for (int a = 1; a <= n; a++) {
        int b = n / a;

        if (a * b == n && a <= b) {
            x = a;
            y = b;
        }
    }

    std::cout << x << " " << y << '\n';
    return 0;
}