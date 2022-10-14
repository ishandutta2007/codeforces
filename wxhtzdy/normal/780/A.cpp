#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int ans = 0, bal = 0;
    std::vector<bool> was(n + 1, false);
    for (int i = 0; i < 2 * n; i++) {
        int x;
        std::cin >> x;

        if (!was[x]) {
            was[x] = true;
            bal++;
            ans = std::max(ans, bal);
        } else bal--;
    }

    std::cout << ans << "\n";
    return 0;
}