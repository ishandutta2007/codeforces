#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    if (n == 1) {
        printf("%d\n", a[0]);
        return 0;
    }
    long long ans = a[n - 1] - a[0];
    for (int i = 1; i < n - 1; ++i) ans += abs(a[i]);
    printf("%lld\n", ans);
    return 0;
}