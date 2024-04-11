#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int l[maxn], r[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &l[i], &r[i]); 
    sort(l, l + n), sort(r, r + n);
    long long ans = n;
    for (int i = 0; i < n; ++i) ans += max(l[i], r[i]);
    printf("%lld\n", ans);
}