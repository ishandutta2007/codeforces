#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = 1e10;
long long a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    // b[n] = inf;
    long long d = 1, ans = (int)2e9; while (d <= (int)2e9) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) {
        int r = ans - d, i = 0, j = 0;
        for (i = 0, j = 0; i < m; ++i) {
            while (j < n && abs(a[j] - b[i]) <= r) ++j;
        }
        if (j == n) ans -= d;
    }
    cout << ans << endl;
    return 0;
}