#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
const int N = 1e5 + 5;

int n, m, x, y, k, h = 0;
int cnt[N], w[N], sz[N], dp[N];
char ans[N];
vector<int> g[N], node[N];

void dfs(int x, int d) {
    node[d].PB(x), h = max(h, d);
    for (auto u : g[x])
        dfs(u, d + 1);
}

int main() {
    scanf("%d%d", &n, &k);
    rep(i, 2, n) scanf("%d", &x), g[x].PB(i);
    dfs(1, 1);

    rep(i, 1, h) cnt[node[i].size()]++;
    m = 0;
    rep(i, 1, n) if (cnt[i]) {
        for (int ww = 1; cnt[i] >= ww; ww <<= 1)
            w[++m] = ww * i, sz[m] = i, cnt[i] -= ww;
        if (cnt[i])
            w[++m] = cnt[i] * i, sz[m] = i;
    }
    dp[0] = -1;
    rep(i, 1, m) rrep(j, n, w[i]) if (!dp[j] && dp[j - w[i]]) dp[j] = i;

    if (dp[k]) {
        memset(cnt, 0, sizeof cnt);
        for (x = k; x; x -= w[y])
            y = dp[x], cnt[sz[y]] += w[y] / sz[y];
        rep(i, 1, h) {
            int sz = node[i].size();
            char ch = cnt[sz] ? 'a' : 'b';
            cnt[sz] ? cnt[sz]-- : 0;
            for (auto x : node[i])
                ans[x] = ch;
        }
        printf("%d\n%s", h, ans + 1);
        return 0;
    }

    rep(i, 1, h) sort(node[i].begin(), node[i].end(), [](int x, int y) { return g[x].size() > g[y].size(); });
    m = n, y = k;
    rep(i, 1, h) {
        int sz = node[i].size();
        if (sz <= max(y, m - y)) {
            for (auto x : node[i])
                ans[x] = sz <= y ? 'a' : 'b';
            y -= sz <= y ? sz : 0;
        } else {
            char ch = y > m - y ? 'a' : 'b';
            x = max(y, m - y);
            rep(j, 0, sz - 1) ans[node[i][j]] = j < x ? ch : 'a' - ch + 'b';
            y = ch == 'a' ? 0 : m - sz;
        }
        m -= sz;
    }
    printf("%d\n%s", h + 1, ans + 1);
    return 0;
}