#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10, maxv = 2e6 + 10;
const long long inf = 1e18;
int a[maxn], cnt[maxv];
long long sum[maxv];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x, y; cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        sum[a[i]] += a[i];
    }
    for (int i = 1; i < maxv; ++i) cnt[i] += cnt[i - 1], sum[i] += sum[i - 1];
    long long ans = inf;
    for (int p = 2; p < maxv; ++p) {
        long long cur = 0;
        for (int k = 1; p * k < maxv; ++k) {
            int dv = (x % y == 0 ? x / y : x / y + 1);
            int d = max(k * p - dv, (k - 1) * p);
            cur += (long long)x * (cnt[d] - cnt[(k - 1) * p]);
            cur += (long long)y * (k * (long long)p * (cnt[k * p] - cnt[d]) - sum[k * p] + sum[d]);
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}