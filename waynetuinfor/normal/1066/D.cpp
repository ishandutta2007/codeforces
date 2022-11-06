#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int d = 20, ans = n;
    function<bool(int)> check = [&](int t) {
        int s = 0, u = 0;
        for (int i = t; i < n; ++i) {
            if (s + a[i] > k) s = a[i], ++u;
            else s += a[i];
        }
        if (s) ++u;
        return u <= m;
    };
    while (d--) {
        if (ans - (1 << d) < 0) continue;
        if (check(ans - (1 << d))) ans -= (1 << d);
    }
    printf("%d\n", n - ans);
    return 0;
}