#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int c[maxn], n, k;

int cal(int l, int r) {
    // cout << "cal = " << l << ' ' << r << endl;
    if (r == n) return 0;
    if (l < 0) return 0;
    int gl = l, gr = r;
    int ret = 0;
    while (gl >= 0 && c[gl] == c[l]) --gl, ++ret;
    while (gr < n && c[gr] == c[r]) ++gr, ++ret;
    if (c[r] == c[l] && ret >= 3) return ret + cal(gl, gr);
    return 0;
}

int main() {
    int k, x; cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) cin >> c[i];
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (c[i] == c[i + 1] && c[i] == x) ans = max(ans, cal(i - 1, i + 2) + 2);
    }
    cout << ans << endl;
    return 0;
}