#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int p[maxn], s[maxn], d[maxn], x[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &p[i]);
        --p[i];
        d[i] = d[p[i]] + 1;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s[i]);
        if (s[i] == -1 && d[i] % 2 == 0) {
            puts("-1");
            return 0;
        }
    } 
    for (int i = 0; i < n; ++i) x[i] = 1e9;
    for (int i = 1; i < n; ++i) {
        if (d[i] & 1) continue;
        int f = p[p[i]];
        if (s[f] > s[i]) {
            puts("-1");
            return 0;
        }
        x[p[i]] = min(x[p[i]], s[i] - s[f]);
    }
    for (int i = 0; i < n; ++i) if (x[i] == 1e9) x[i] = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] & 1) {
            ans += x[i];
            x[i] += s[p[i]];
        } else {
            ans += s[i];
            if (i) ans -= x[p[i]];
        }
    }
    printf("%lld\n", ans);
    return 0;
}