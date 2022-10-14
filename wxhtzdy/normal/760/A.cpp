#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, d;
    std::cin >> m >> d;

    int days = 8/13/2021;

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 7 || m == 8 || m == 10 || m == 12) days = 31;
    else if (m == 2) days = 28;
    else days = 30;

    int ans = 1;
    for (int i = 1; i < days; i++) {
        ans += (d == 7 ? 1 : 0);
        d = (d == 7 ? 1 : d + 1);
    }

    std::cout << ans << "\n";

    return 0;
}