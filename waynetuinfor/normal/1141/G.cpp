#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int e[maxn], c[maxn], z[maxn];
vector<int> g[maxn];

int dfs(int x, int p, int f, int r) {
    int ch = (f >= 0);
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = (e[g[x][i]] ^ x);
        if (u != p) ++ch; 
    }
    int res = 0;
    if (ch > r) {
        res = 1;
        int y = (f == -1 ? 0 : f);
        for (int i = 0; i < (int)g[x].size(); ++i) {
            int u = (e[g[x][i]] ^ x);
            if (u != p) {
                z[g[x][i]] = y;
                res += dfs(u, x, y, r);
            }
        }
    } else {
        int y = 0;
        for (int i = 0; i < (int)g[x].size(); ++i) {
            int u = (e[g[x][i]] ^ x);
            if (u != p) {
                if (y == f) y++;
                z[g[x][i]] = y;
                res += dfs(u, x, y, r);
                y++;
            }
        }
    }
    return res;
}

bool check(int r, int k, int n) {
    int res = dfs(0, -1, -1, r);
    if (res > k) return false;
    for (int i = 0; i < n - 1; ++i) c[i] = z[i];
    return true;
}

int main() {
    int n, k; scanf("%d%d", &n ,&k);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(i);
        g[v].push_back(i);
        e[i] = (u ^ v);
    }
    int ans = n - 1;
    for (int i = 0; i < n - 1; ++i) c[i] = i;
    for (int d = 20; d >= 0; --d) {
        if (ans - (1 << d) >= 1) {
            if (check(ans - (1 << d), k, n))
                ans -= (1 << d);
        }
    }
    for (int i = 0; i < n - 1; ++i) assert(0 <= c[i] && c[i] < ans);
    printf("%d\n", ans);
    for (int i = 0; i < n - 1; ++i) printf("%d ", c[i] + 1);
    puts("");
}