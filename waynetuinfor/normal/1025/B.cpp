#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn][2];

int main() {
    int n; scanf("%d", &n);
    long long g = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        g = __gcd(g, a[i][0] * 1ll * a[i][1]);
    }
    if (g == 1) {
        puts("-1");
        return 0;
    }
    long long ans = g;
    for (int i = 0; i < n; ++i) {
        bool f = false;
        for (int j = 0; j < 2; ++j) {
            if (__gcd(ans, 1ll * a[i][j]) != 1) 
                ans = __gcd(ans, 1ll * a[i][j]), f = true;
        }
        if (!f) {
            puts("-1");
            return 0;
        }
    }
    printf("%lld\n", ans);
}