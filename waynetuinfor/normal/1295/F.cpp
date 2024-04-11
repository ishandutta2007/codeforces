#include <bits/stdc++.h>
using namespace std;

int main() {
    constexpr int kMod = 998244353;
    int n; scanf("%d", &n);
    vector<int> l(n), r(n), ds = {0, kMod - 1};
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        ds.push_back(l[i]);
        ds.push_back(r[i] + 1);
    }
    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());
    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    vector<int> tl(n), tr(n);
    for (int i = 0; i < n; ++i) {
        tl[i] = lower_bound(ds.begin(), ds.end(), l[i]) - ds.begin();
        tr[i] = lower_bound(ds.begin(), ds.end(), r[i] + 1) - ds.begin();
    }

    auto fpow = [&](int a, int n) {
        int res = 1;
        while (n > 0) {
            if (n & 1) res = 1LL * res * a % kMod;
            a = 1LL * a * a % kMod;
            n >>= 1;
        }
        return res;
    };

    vector<int> inv(n + 1);
    for (int i = 1; i <= n; ++i) inv[i] = fpow(i, kMod - 2);

    auto Choose = [&](int n, int k) {
        int res = 1;
        for (int i = 0; i < k; ++i) res = 1LL * res * (n - i) % kMod;
        for (int i = 0; i < k; ++i) res = 1LL * res * inv[k - i] % kMod;
        return res;
    };
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i + 1 < ds.size(); ++i) {
        vector<int> nxt(n + 1);
        for (int j = 0; j <= n; ++j) {
            (nxt[j] += dp[j]) %= kMod;
            for (int k = j + 1; k <= n; ++k) {
                bool ok = true;
                for (int p = j; p < k; ++p) ok &= tl[p] <= i && tr[p] > i;
                if (ok) {
                    nxt[k] += 1LL * dp[j] * Choose(ds[i + 1] - ds[i] + k - j - 1, k - j) % kMod;
                    nxt[k] %= kMod;
                }
            }
        }
        nxt.swap(dp);
    }
    int ans = dp[n];
    for (int i = 0; i < n; ++i) ans = 1LL * ans * fpow(r[i] - l[i] + 1, kMod - 2) % kMod;
    printf("%d\n", ans);
    return 0;
}