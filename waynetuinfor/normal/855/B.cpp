#include <bits/stdc++.h>
#define int long long
using namespace std;

const long long inf = 3e18;
const int maxn = 1e5 + 10;
int a[maxn], b[maxn], c[maxn];

int32_t main() {
    int n, p, q, r; cin >> n >> p >> q >> r; 
    long long ans = -inf;
    fill(b, b + maxn, -inf); fill(c, c + maxn, -inf);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) b[i] = max(b[i - 1], a[i] * p);
    for (int i = n; i >= 1; --i) c[i] = max(c[i + 1], a[i] * r);
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, a[i] * q + b[i] + c[i]);
    }
    cout << ans << endl;
}