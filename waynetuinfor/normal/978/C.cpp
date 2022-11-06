#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
long long a[maxn], s[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), s[i] = s[i - 1] + a[i];
    while (m--) {
        long long b; scanf("%lld", &b);
        int p = lower_bound(s + 1, s + n + 1, b) - s;
        b -= s[p - 1];
        printf("%d %lld\n", p, b);
    }
}