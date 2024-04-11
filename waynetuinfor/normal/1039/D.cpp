#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> g[maxn];
int ans[maxn], cnt;

int dfs(int x, int p, int k) {
    int a = 0, b = 0;
    for (const int &u : g[x]) {
        if (u == p) continue;
        int c = dfs(u, x, k);
        if (c > a) b = a, a = c;
        else if (c > b) b = c;
    }
    int res = a + 1;
    if (a + b + 1 >= k) ++cnt, res = 0;
    return res;
}

int solve(int k) {
    cnt = 0;
    int res = dfs(0, -1, k);
    if (res >= k) ++cnt;
    return cnt;
}

void dvcq(int l, int r, int ql, int qr) {
    if (l > r || ql > qr) return;
    if (ql == qr) {
        for (int i = l; i <= r; ++i)
            ans[i] = ql;
        return;
    }
    int m = (l + r) >> 1;
    int f = solve(m);
    ans[m] = f;
    assert(ql <= f && f <= qr);
    dvcq(l, m - 1, f, qr);
    dvcq(m + 1, r, ql, f);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dvcq(1, n, 0, n);
    for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
    return 0;
}