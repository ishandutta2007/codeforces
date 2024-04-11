#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, a[N];
signed main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    int ans = 0, rm = 0;
    for (int i = n; i; --i) {
        rm += a[i] / 2;
        if (a[i] & 1) {
            if (rm) ++ans, --rm;
        }
    }
    ans += rm * 2 / 3;
    printf("%lld\n", ans);
    return 0;
}