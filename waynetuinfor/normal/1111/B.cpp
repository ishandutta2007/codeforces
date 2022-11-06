#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn];

int main() {
    int n, k, m; scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    long long s = accumulate(a, a + n, 0ll);
    sort(a, a + n);
    double ans = 0.0;
    for (int i = 0; i < n; ++i) {
        if (m < 0) break;
        long long o = min(1ll * m, (n - i) * 1ll * k);
        ans = max(ans, 1.0 * (s + o) / (n - i));
        --m;
        s -= a[i];
    } 
    printf("%.20lf\n", ans);
}