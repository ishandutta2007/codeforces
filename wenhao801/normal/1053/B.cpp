#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long
int n, a[300300], s[300300], o[300300], e[300300];

int main () {
    cin >> n; int i, j;
    e[0] = 1;
    for (i = 1; i <= n; i++) {
        ll x;
        scanf("%lld", &x);
        a[i] = __builtin_popcountll(x);
        s[i] = s[i - 1] + a[i];
        o[i] = o[i - 1], e[i] = e[i - 1];
        if (s[i] & 1) ++o[i]; else ++e[i];
    }
    ll ans = 0;
    for (i = 1; i <= n; i++) {
        int res, mx = a[i], sum = a[i];
        for (j = 1; j <= 70 && i - j >= 1; j++) {
            mx = max(mx, a[i - j]);
            sum += a[i - j];
            if (sum - mx >= mx && sum % 2 == 0) ++ans;
        }
        res = max(0, i - 71);
        if (s[i] & 1) ans += o[res - 1]; else ans += e[res - 1];
    }
    printf("%lld\n", ans);
    return 0;
}