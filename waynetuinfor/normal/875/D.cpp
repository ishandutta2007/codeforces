#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10, lg = 30;
int a[maxn];

struct sparse {
    int arr[lg][maxn];
    void init(int n) {
        for (int i = 0; i < n; ++i) arr[0][i] = a[i];
        for (int i = 1; (1 << i) <= n; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) arr[i][j] = (arr[i - 1][j] | arr[i - 1][j + (1 << (i - 1))]);
        }
    }
    int query(int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);
        return arr[p][l] | arr[p][r - (1 << p) + 1];
    }
} sp;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sp.init(n);
    map<int, int> pos;
    int ans = n * 1ll * (n - 1) / 2;
    for (int i = 0; i < n; ++i) {
        int d = 1; while (d <= n) d <<= 1;
        int l = i, r = i;
        while (d >>= 1) {
            if (l - d >= 0) if (sp.query(l - d, i) == a[i]) l -= d;
            if (r + d < n) if (sp.query(i, r + d) == a[i]) r += d;
        }
        if (pos.find(a[i]) != pos.end()) l = max(l, pos[a[i]] + 1);
        // cout << "l = " << l << " r = " << r << endl;
        ans -= (r - i + 1) * (i - l + 1) - 1;
        pos[a[i]] = i;
    }
    // ans -= n;
    cout << ans << endl;
    return 0;
}