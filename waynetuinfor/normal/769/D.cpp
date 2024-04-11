#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], cnt[maxn];
long long xo[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    int m = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], m = max(m, a[i]), ++cnt[a[i]];
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j < i; ++j) xo[i ^ j] += (long long)cnt[i] * (long long)cnt[j];
        xo[i ^ i] += (long long)cnt[i] * (long long)(cnt[i] - 1) / 2;
    }
    long long ans = 0;
    for (int i = 0; i < (1 << 14); ++i) {
        int bit = 0;
        for (int j = 0; j < 14; ++j) if ((1 << j) & i) ++bit;
        if (bit == k) ans += xo[i];
    }
    cout << ans << endl;
    return 0;
}