#include <bits/stdc++.h>

using i64 = long long;

constexpr int md = 1E9 + 7;

i64 add(i64 a, i64 b) { a += b; return a >= md ? a - md : a; }
i64 mul(i64 a, i64 b) { return a * b % md; }

i64 power(i64 a, i64 b) {
    if (b == 0) return 1;
    i64 res = power(a, b >> 1);
    res = mul(res, res);
    if (b & 1) res = mul(res, a);
    return res;
}

constexpr int N = 2E5 + 5;

i64 fact[N], inv[N];

i64 choose(int n, int k) {
    if (n < k) return 0LL;
    return mul(fact[n], mul(inv[k], inv[n - k]));
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    i64 ans = 0;
    for (int i = 0, j = -1; i < n; i++) {
        while (j + 1 < n && a[i] >= a[j + 1] - k) j++;

        ans = add(ans, choose(j - i, m - 1));
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    fact[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
    for (int i = 1; i < N; i++) inv[i] = power(fact[i], md - 2);

    int tt;
    std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}