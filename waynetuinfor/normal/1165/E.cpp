#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int mod = 998244353;
int a[maxn], b[maxn], c[maxn];
long long d[maxn], e[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    sort(b, b + n);

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);

    for (int i = 0; i < n; ++i)
        d[i] = (i + 1) * 1ll * (n - i) * a[i];

    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return d[i] < d[j];
    });

    for (int i = 0; i < n; ++i) c[ord[i]] = b[n - 1 - i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (d[i] % mod) * 1ll * c[i] % mod;
        ans %= mod;
    }


    printf("%d\n", ans);
    return 0;
}