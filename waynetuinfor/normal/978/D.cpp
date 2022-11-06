#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
long long b[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
    if (n <= 2) {
        puts("0");
        return 0;
    }
    int ans = 1e9;
    for (int x = -1; x <= 1; ++x) for (int y = -1; y <= 1; ++y) {
        long long diff = (b[1] + y) - (b[0] + x);
        int tans = (x != 0) + (y != 0);
        for (int i = 2; i < n; ++i) {
            long long ex = (b[1] + y) + (i - 1) * 1ll * diff;
            if (abs(b[i] - ex) > 1) tans = 1e9;
            else tans += abs(b[i] - ex);
        }
        ans = min(ans, tans);
    }
    if (ans > maxn) puts("-1");
    else printf("%d\n", ans);
    return 0;
}