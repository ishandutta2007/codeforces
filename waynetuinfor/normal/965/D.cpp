#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];

int main() {
    int l, w; scanf("%d %d", &w, &l);
    for (int i = 1; i < w; ++i) scanf("%d", &a[i]);
    long long s = 0;
    for (int i = 1; i <= l; ++i) s += a[i];
    long long ans = s;
    for (int i = l + 1; i < w; ++i) {
        s -= a[i - l];
        s += a[i];
        ans = min(ans, s);
    }
    printf("%lld\n", ans);
    return 0;
}