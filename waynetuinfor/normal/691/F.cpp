#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e6 + 5;
int c[maxn], cs[maxn];
long long s[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        ++c[x];
    }
    for (int i = 1; i < maxn; ++i) cs[i] = cs[i - 1] + c[i];
    long long exc = 0;
    for (int i = 1; i < maxn; ++i) if (c[i] > 0) {
        for (int j = i; j < maxn; j += i) s[j] += c[i] * 1ll * c[j / i];
        int l = (maxn % i == 0 ? maxn / i : maxn / i + 1);
        exc += c[i] * 1ll * (cs[maxn - 1] - cs[l - 1]);
        if (i * 1ll * i < maxn) s[i * i] -= c[i];
        else exc -= c[i];
    }
    for (int i = 1; i < maxn; ++i) s[i] += s[i - 1];
    int m; scanf("%d", &m);
    while (m--) {
        int p; scanf("%d", &p);
        printf("%lld\n", exc + s[maxn - 1] - s[p - 1]);
    }
    return 0;
}