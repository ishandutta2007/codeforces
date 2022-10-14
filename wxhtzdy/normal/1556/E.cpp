#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int b[n];
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    i64 sum[n + 1];
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + b[i] - a[i];
    }

    constexpr int L = 20;

    i64 mn[n][L], mx[n][L];
    for (int i = 0; i < n; i++) {
        mn[i][0] = sum[i];
        mx[i][0] = sum[i];
    }

    for (int j = 1; j < L; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            mn[i][j] = std::min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
            mx[i][j] = std::max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
        }
    }

    int logs[n + 1];
    logs[0] = 0;
    logs[1] = 0;
    for (int i = 2; i <= n; i++) {
        logs[i] = logs[i / 2] + 1;
    }

    std::function<i64(int, int)> Min = [&](int l, int r) {
        int i = logs[r - l];
        return std::min(mn[l][i], mn[r - (1 << i)][i]);
    };

    std::function<i64(int, int)> Max = [&](int l, int r) {
        int i = logs[r - l];
        return std::max(mx[l][i], mx[r - (1 << i)][i]);
    };

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        --l;

        if (sum[r] != sum[l]) {
            std::cout << "-1\n";
            continue;
        }

        i64 x = Min(l, r);
        if (x < sum[l]) {
            std::cout << "-1\n";
            continue;
        }

        std::cout << Max(l, r) - sum[l] << "\n";
    }
    return 0;
}