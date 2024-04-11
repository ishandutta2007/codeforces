#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int a[maxn], b[maxn];

int main() {
    int n, k1, k2; scanf("%d %d %d", &n, &k1, &k2);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) scanf("%d", b + i);
    while (k1--) {
        int p = 0;
        for (int i = 0; i < n; ++i) if (abs(a[i] - b[i]) > abs(a[p] - b[p])) p = i;
        if (a[p] > b[p]) --a[p];
        else ++a[p];
    }
    while (k2--) {
        int p = 0;
        for (int i = 0; i < n; ++i) if (abs(a[i] - b[i]) > abs(a[p] - b[p])) p = i;
        if (a[p] > b[p]) ++b[p];
        else --b[p];
    }
    long long e = 0;
    for (int i = 0; i < n; ++i) e += (a[i] - b[i]) * 1ll * (a[i] - b[i]);
    printf("%lld\n", e);
    return 0;
}