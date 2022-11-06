#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        long long n; scanf("%lld", &n);
        int a, b; scanf("%d%d", &a, &b);
        long long ans = n * a;
        if (n % 2 == 0) ans = min(ans, n * b / 2);
        else ans = min(ans, a + (n - 1) * b / 2);
        printf("%lld\n", ans);
    }
}