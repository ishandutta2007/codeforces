#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, sq = 320;
int ans[sq][maxn], a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int lim = (int)sqrt(n);
    for (int i = 1; i <= lim; ++i) for (int j = n; j >= 0; --j) {
        if (j + a[j] + i > n) ans[i][j] = 1;
        else ans[i][j] = 1 + ans[i][j + a[j] + i];
    }
    int q; cin >> q;
    while (q--) {
        int p, k; cin >> p >> k;
        if (k <= lim) cout << ans[k][p] << endl;
        else {
            int cnt = 0;
            while (p + a[p] + k <= n) ++cnt, p += a[p] + k;
            cout << cnt + 1 << endl;
        }
    }
    return 0;
}