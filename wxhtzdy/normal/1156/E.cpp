#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int p[n];
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    int mx[n][20];
    for (int i = 0; i < n; i++) {
        mx[i][0] = p[i];
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            mx[i][j] = std::max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
        }
    }

    auto queryMax = [&](int l, int r) {
        int k = std::__lg(r - l + 1);
        return std::max(mx[l][k], mx[r - (1 << k) + 1][k]);
    };

    int pos[n + 1];
    for (int i = 0; i < n; i++) {
        pos[p[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        {
            int lo = 0, hi = i;
            while (lo <= hi) {
                int mi = (lo + hi) / 2;
                if (queryMax(mi, i) == p[i]) {
                    l = mi;
                    hi = mi - 1;
                } else {
                    lo = mi + 1;
                }
            }
        }
        {
            int lo = i, hi = n - 1;
            while (lo <= hi) {
                int mi = (lo + hi) / 2;
                if (queryMax(i, mi) == p[i]) {
                    r = mi;
                    lo = mi + 1;
                } else {
                    hi = mi - 1;
                }
            }
        }

        //std::cout << i << " " << l << " " << r << "\n";

        if (i - l < r - i) {
            for (int j = l; j < i; j++) {
                if (i <= pos[p[i] - p[j]] && pos[p[i] - p[j]] <= r) ans++;
            }
        } else {
            for (int j = i + 1; j <= r; j++) {
                if (l <= pos[p[i] - p[j]] && pos[p[i] - p[j]] <= i) ans++;
            }
        }
    }

    std::cout << ans << "\n";

    return 0;
}