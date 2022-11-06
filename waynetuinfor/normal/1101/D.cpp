#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<int> v[maxn], g[maxn];
int a[maxn], dv[maxn], fd, fr;
bool vis[maxn];

void dfs(int x, int y, int p, int d) {
    vis[x] = true;
    if (d > fd) {
        fd = d;
        fr = x;
    }
    for (const int &u : g[x]) {
        if (u == p) continue;
        if (a[u] % y) continue;
        dfs(u, y, x, d + 1);
    }
}

void sieve() {
    vector<int> p;
    for (int i = 2; i < maxn; ++i) {
        if (!dv[i]) dv[i] = i, p.push_back(i);
        for (int j = 0; i * p[j] < maxn; ++j) {
            dv[i * p[j]] = p[j];
            if (i % p[j] == 0) break;
        }
    }
}

vector<int> fact(int x) {
    vector<int> res;
    for (int y = x; y < maxn; y += x) {
        for (int i = 0; i < (int)v[y].size(); ++i)
            res.push_back(v[y][i]);
    } 
    return res;
}

int main() {
    sieve();
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        v[a[i]].push_back(i);
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    for (int i = 2; i < maxn; ++i) {
        if (dv[i] != i) continue;
        vector<int> p = fact(i);
        for (int j = 0; j < (int)p.size(); ++j) {
            int x = p[j];
            if (vis[x]) continue;
            fd = fr = -1;
            dfs(x, i, -1, 1);
            fd = -1;
            dfs(fr, i, -1, 1);
            ans = max(ans, fd);
        }
        for (int j = 0; j < (int)p.size(); ++j) {
            int x = p[j];
            vis[x] = false;
        }
    }
    printf("%d\n", ans);
    return 0;
}