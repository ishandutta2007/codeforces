#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int sum[105];
    for (int t = 1; t <= 100; t++) {
        sum[t] = 0;
        for (int i = 0; i < n; i++) {
            if (t > a[i]) {
                sum[t] += std::max(0, std::min(t - a[i], t - a[i] - 1));
            } else {
                sum[t] += std::max(0, std::min(a[i] - t, a[i] - t - 1));
            }
        }
    }

    int mn = 1;
    for (int i = 2; i <= 100; i++) {
        if (sum[i] < sum[mn]) {
            mn = i;
        }
    }

    std::cout << mn << " " << sum[mn] << "\n";

    return 0;
}