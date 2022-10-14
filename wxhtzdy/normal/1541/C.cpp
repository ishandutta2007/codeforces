#include <bits/stdc++.h>
using namespace std;

void test_case() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * 1LL * (n - i - 1);
        ans -= a[i] * 1LL * i;
    }
    printf("%lld\n", ans + a[n - 1]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        test_case();
    return 0;
}