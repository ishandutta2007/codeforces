#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int u[maxn], v[maxn], w[maxn], q[maxn], fa[maxn], sz[maxn];
long long ans, res[maxn];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    ans -= 1LL * sz[x] * (sz[x] - 1) / 2;
    ans -= 1LL * sz[y] * (sz[y] - 1) / 2;
    sz[y] += sz[x];
    ans += 1LL * sz[y] * (sz[y] - 1) / 2;
    fa[x] = y;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        --u[i], --v[i];
    }

    for (int i = 0; i < m; ++i) scanf("%d", &q[i]);

    vector<int> ed(n - 1), qr(m);
    iota(ed.begin(), ed.end(), 0);
    iota(qr.begin(), qr.end(), 0);

    sort(ed.begin(), ed.end(), [&](int i, int j) { return w[i] < w[j]; });
    sort(qr.begin(), qr.end(), [&](int i, int j) { return q[i] < q[j]; });

    for (int i = 0; i < n; ++i) fa[i] = i, sz[i] = 1;

    for (int i = 0, j = 0; i < m; ++i) {
        while (j < n - 1 && w[ed[j]] <= q[qr[i]]) {
            merge(u[ed[j]], v[ed[j]]);
            ++j;
        }
        res[qr[i]] = ans;
    }
    for (int i = 0; i < m; ++i) printf("%lld ", res[i]);
    puts("");
}