#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

const int maxn = 200000 + 5;
int n, m, k, x, s, a[maxn], b[maxn], c[maxn], d[maxn], ans;

signed main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    cin >> x >> s;
    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    for (int i = 0; i < k; ++i) cin >> c[i];
    for (int i = 0; i < k; ++i) cin >> d[i];
    ans = n * x;
    for (int i = 0; i < m; ++i) {
        if (s - b[i] < 0) continue;
        auto it = upper_bound(d, d + k, s - b[i]);
        int best;
        if (it == d + k) best = k - 1;
        else best = it - d - 1;
        if (d[best] + b[i] > s) continue;
        int t = (n - c[best]) * a[i];
        ans = min(ans, t);
    }
    for (int i = 0; i < m; ++i) if (b[i] <= s) ans = min(ans, n * a[i]);
    for (int i = 0; i < k; ++i) if (d[i] <= s) ans = min(ans, x * (n - c[i]));
    cout << ans << '\n';
    return 0;
}