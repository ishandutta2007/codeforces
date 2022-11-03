#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, m, a[N], sm[N];
signed main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    --n;
    for (int i = 1; i <= n; ++i) a[i] = a[i + 1] - a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        sm[i] = sm[i - 1] + (n - i + 2) * (a[i] - a[i - 1]);
    }
    scanf("%lld", &m);
    for (int id = 1, l, r; id <= m; ++id) {
        scanf("%lld%lld", &l, &r);
        r -= l;
        int ps = upper_bound(a + 1, a + n + 1, r) - a - 1;
        printf("%lld ", sm[ps] + (n - ps + 1) * (r - a[ps] + 1));
    }
    puts("");
    return 0;
}