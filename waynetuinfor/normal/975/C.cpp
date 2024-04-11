#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];
long long k[maxn], s[maxn];

int main() {
    int n, q; scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= q; ++i) scanf("%lld", &k[i]);
    int p = 1;
    long long z = 0;
    for (int i = 1; i <= q; ++i) {
        if (s[n] <= z + k[i]) {
            printf("%d\n", n);
            z = 0;
            continue;
        }
        int t = upper_bound(s + 1, s + n + 1, z + k[i]) - s - 1;
        printf("%d\n", n - t);
        z += k[i];
    }
    return 0;
}