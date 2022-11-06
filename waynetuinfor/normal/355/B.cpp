#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1000 + 5, inf = 1e18;
int a[maxn], b[maxn];

int32_t main() {
    int c1, c2, c3, c4; cin >> c1 >> c2 >> c3 >> c4;
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    int bs = inf, k = 0;
    for (int i = 0; i < n; ++i) k += min(c1 * a[i], c2);
    bs = min(bs, min(k, c3));
    int tr = inf; k = 0;
    for (int i = 0; i < m; ++i) k += min(c1 * b[i], c2);
    tr = min(tr, min(k, c3));
    cout << min(bs + tr, c4) << endl;
}