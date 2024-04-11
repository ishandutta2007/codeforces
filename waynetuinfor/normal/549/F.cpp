#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn], k, c[maxn];
long long s[maxn];

long long dvcq(int l, int r) {
    if (l == r) return 0;
    int m = l + r >> 1;
    long long ret = 0;
    int lmax = 0, rmax = 0, p = m + 1;
    for (int i = m; i >= l; --i) {
        lmax = max(lmax, a[i]);
        while (p <= r && max(rmax, a[p]) < lmax) rmax = max(rmax, a[p]), ++c[(s[p] - s[m]) % k], ++p;
        int now = (s[m] - s[i - 1] - lmax) % k;
        ret += c[(k - now) % k];
    }
    for (int i = m + 1; i < p; ++i) --c[(s[i] - s[m]) % k];
    lmax = rmax = 0; p = m;
    for (int i = m + 1; i <= r; ++i) {
        rmax = max(rmax, a[i]);
        while (p >= l && max(lmax, a[p]) <= rmax) lmax = max(lmax, a[p]), ++c[(s[m] - s[p - 1]) % k], --p;
        int now = (s[i] - s[m] - rmax) % k;
        ret += c[(k - now) % k];
    }
    for (int i = m; i > p; --i) --c[(s[m] - s[i - 1]) % k];
    ret += dvcq(l, m) + dvcq(m + 1, r);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n >> k;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; ++i) cin >> a[i], s[i] = s[i - 1] + a[i];
    cout << dvcq(1, n) << endl;
}