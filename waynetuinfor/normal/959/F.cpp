#include <bits/stdc++.h>
using namespace std;

const int maxn = 1048576, mod = 1e9 + 7;
int a[maxn], l[maxn], x[maxn], ans[maxn];
int z[21], tpow[maxn];
vector<int> qr[maxn];

void insert(vector<int> &p, int z) {
    for (int i = 0; i < p.size(); ++i) z = min(z, z ^ p[i]);
    if (z > 0) p.push_back(z);
}

int main() {
    int n, q; scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", l + i, x + i);
        qr[l[i]].push_back(i);
    }
    tpow[0] = 1;
    for (int i = 1; i < maxn; ++i) tpow[i] = tpow[i - 1] * 1ll * 2 % mod;
    vector<int> p;
    for (int i = 1; i <= n; ++i) {
        insert(p, a[i]);
        for (int j = 0; j < qr[i].size(); ++j) {
            int t = x[qr[i][j]];
            for (int k : p) t = min(t, t ^ k);
            if (t == 0) ans[qr[i][j]] = tpow[i - (int)p.size()];
            else ans[qr[i][j]] = 0;
        }
    } 
    for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
    return 0;
}