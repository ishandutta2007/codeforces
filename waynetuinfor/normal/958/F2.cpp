#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int k[maxn], d[maxn], a[maxn];
bool ok[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    int p = 0;
    for (int i = 1; i <= m; ++i) scanf("%d", k + i), p += (k[i] > 0);
    int s = 0;
    for (int i = 1; i <= m; ++i) d[i] = -k[i], s += d[i];
    int ans = maxn;
    int j = 1, okc = 0;
    for (int i = 1; i <= n; ++i) {
        d[a[i]]++, s++;
        if (d[a[i]] >= 0 && !ok[a[i]] && k[a[i]] > 0) ok[a[i]] = true, ++okc; 
        while (j <= i && d[a[j]] > 0) {
            --s;
            --d[a[j]];
            ++j;
        }
        if (okc == p) ans = min(ans, s);
    }
    if (ans == maxn) ans = -1;
    printf("%d\n", ans);
}