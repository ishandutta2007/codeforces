#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], cnt[maxn];
bool v[maxn];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], ++cnt[a[i]];
    for (int i = 1; i < maxn; ++i) cnt[i] += cnt[i - 1];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int now = 0;
        if (v[a[i]]) continue;
        for (int p = 1; a[i] * p < maxn; ++p) {
            int l = a[i] * p, r = a[i] * (p + 1) - 1;
            now += a[i] * p * (cnt[min(r, maxn - 1)] - cnt[l - 1]);
            if (cnt[min(r, maxn - 1)] == 0) break;
        }
        v[a[i]] = true;
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}