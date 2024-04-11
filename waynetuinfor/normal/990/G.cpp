#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<int> g[maxn], dv[maxn];
int a[maxn], sz[maxn], p[maxn], deg[maxn];
long long ans[maxn];
bool v[maxn];

void init(int n) {
    for (int i = 0; i < n; ++i) 
        p[i] = i, sz[i] = 1;
}

int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    sz[y] += sz[x];
    p[x] = y;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), ++deg[a[i]];
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d %d", &x, &y); --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j * j <= a[i]; ++j) if (a[i] % j == 0) {
            dv[j].push_back(i);
            if (a[i] / j != j) dv[a[i] / j].push_back(i);
        }
    } 
    init(n);
    for (int i = 1; i < maxn; ++i) {
        for (int j : dv[i]) {
            v[j] = true;
            for (int u : g[j]) if (v[u]) merge(j, u);
        }
        for (int j : dv[i]) v[j] = false;
        for (int j : dv[i]) if (!v[find(j)]) {
            v[find(j)] = true;
            ans[i] += sz[find(j)] * 1ll * (sz[find(j)] - 1) / 2;
        }
        for (int j : dv[i]) {
            v[j] = false;
            p[j] = j;
            sz[j] = 1;
        }
    }
    for (int i = maxn - 1; i >= 1; --i) {
        for (int j = i + i; j < maxn; j += i) ans[i] -= ans[j];
    }
    for (int i = 1; i < maxn; ++i) if (ans[i] + deg[i] > 0) printf("%d %lld\n", i, ans[i] + deg[i]);
    return 0;
}