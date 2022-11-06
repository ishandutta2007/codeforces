#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const long long inf = 1e18;
int w[maxn];
long long sl[maxn], sr[maxn];

int main() {
    int n, l, r, ql, qr; scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);
    for (int i = 1; i <= n; ++i) scanf("%d", w + i);
    for (int i = 1; i <= n; ++i) sl[i] = sl[i - 1] + w[i] * l;
    for (int i = n; i >= 1; --i) sr[i] = sr[i + 1] + w[i] * r;
    long long ans = inf;
    for (int i = 0; i <= n; ++i) {
        int pa = i, pb = n - i;
        long long cost = 0;
        if (pa > pb) cost = (pa - pb - 1) * ql;
        else if (pb > pa) cost = (pb - pa - 1) * qr;
        ans = min(ans, sl[i] + sr[i + 1] + cost);
    }
    printf("%lld\n", ans);
    return 0;
}