#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, g, b; scanf("%d%d%d", &n, &g, &b);
        int m = (n + 1) / 2;
        long long ans = n;
        int k = (m + g - 1) / g;
        ans = max(ans, 1LL * (k - 1) * (g + b) + m - 1LL * (k - 1) * g);
        printf("%lld\n", ans);
    }
    return 0;
}