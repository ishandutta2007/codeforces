#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 1) --ans;
        else if (a[i] + a[i] < b[i]) --ans;
        else ans += b[i] / 2 * 1ll * (b[i] - b[i] / 2);
    }
    printf("%lld\n", ans);
    return 0;
}