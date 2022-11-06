#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int j = 0;
    long long p = 0;
    for (int i = 0; i < n; ++i) {
        long long x = min(1ll * a[i] / 2, p);
        a[i] -= x * 2;
        p -= x;
        ans += x;
        ans += a[i] / 3;
        a[i] %= 3;
        p += a[i];
    }
    printf("%lld\n", ans);
}