#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto b = a;
    std::sort(b.begin(), b.end());

    int ans = (b[0] + 1) / 2 + (b[1] + 1) / 2;
    for (int i = 0; i + 2 < n; i++) {
        ans = std::min(ans, (a[i] + a[i + 2] + 1) / 2);
    }

    for (int i = 0; i + 1 < n; i++) {
        int mn = std::min(a[i], a[i + 1]);
        int mx = std::max(a[i], a[i + 1]);
        if (mn * 2 < mx) {
            ans = std::min(ans, (mx + 1) / 2);
        } else {
            int d = mx - mn;
            ans = std::min(ans, d + (mx + mn - 3 * d + 2) / 3);        
        }
    }

    std::cout << ans;

    return 0;
}