#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int Case, n, x;
    scanf("%lld", &Case);
    while (Case--) {
        scanf("%lld", &n);
        int num = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &x);
            if (x >= 0) num += x;
            else {
                x = -x;
                if (num >= x) num -= x; else ans += x - num, num = 0;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}