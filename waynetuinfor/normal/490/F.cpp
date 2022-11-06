#include <bits/stdc++.h>
using namespace std;

const int maxn = 6000 + 10;
int r[maxn];
int16_t dpinc[maxn][maxn], dpdec[maxn][maxn], tinc[2][maxn], tdec[2][maxn], ans;
vector<int> G[maxn], ds;

void dfs(int now, int fa) {
    dpinc[now][r[now]] = dpdec[now][r[now]] = 1;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        for (int j = 1; j <= ds.size(); ++j) {
            dpdec[now][j] = max(dpdec[now][j], dpdec[u][j]);
            if (dpdec[u][j] > dpdec[tdec[0][j]][j]) tdec[1][j] = tdec[0][j], tdec[0][j] = u;
            else if (dpdec[u][j] > dpdec[tdec[1][j]][j]) tdec[1][j] = u;
            if (j < r[now]) dpdec[now][r[now]] = max(dpdec[now][r[now]], (int16_t)(dpdec[u][j] + 1));
            ans = max(ans, dpdec[now][j]);
        }
        for (int j = ds.size(); j >= 1; --j) {
            dpinc[now][j] = max(dpinc[now][j], dpinc[u][j]);
            if (dpinc[u][j] > dpinc[tinc[0][j]][j]) tinc[1][j] = tinc[0][j], tinc[0][j] = u;
            else if (dpinc[u][j] > dpinc[tinc[1][j]][j]) tinc[1][j] = u;
            if (j > r[now]) dpinc[now][r[now]] = max(dpinc[now][r[now]], (int16_t)(dpinc[u][j] + 1));
            ans = max(ans, dpdec[now][j]);
        }
    }
    ans = max(ans, max(dpinc[now][r[now]], dpdec[now][r[now]]));
    memset(tinc, 0, sizeof(tinc)); memset(tdec, 0, sizeof(tdec));
    for (int u : G[now]) if (u != fa) {
        for (int j = 1; j <= ds.size(); ++j) {
            if (dpdec[u][j] > dpdec[tdec[0][j]][j]) tdec[1][j] = tdec[0][j], tdec[0][j] = u;
            else if (dpdec[u][j] > dpdec[tdec[1][j]][j]) tdec[1][j] = u;
        }
        for (int j = ds.size(); j >= 1; --j) {
            if (dpinc[u][j] > dpinc[tinc[0][j]][j]) tinc[1][j] = tinc[0][j], tinc[0][j] = u;
            else if (dpinc[u][j] > dpinc[tinc[1][j]][j]) tinc[1][j] = u;
        }
    }
    for (int u : G[now]) if (u != fa) {
        int16_t curmax = 0;
        for (int j = ds.size(); j >= 1; --j) {
            ans = max(ans, (int16_t)(dpdec[u][j] + curmax));
            if (tinc[0][j] != u) curmax = max(curmax, dpinc[tinc[0][j]][j]);
            else curmax = max(curmax, dpinc[tinc[1][j]][j]);
        }
        curmax = 0;
        for (int j = 1; j <= ds.size(); ++j) {
            ans = max(ans, (int16_t)(dpinc[u][j] + curmax));
            if (tdec[0][j] != u) curmax = max(curmax, dpdec[tdec[0][j]][j]);
            else curmax = max(curmax, dpdec[tdec[1][j]][j]);
        }
    }
    for (int u : G[now]) if (u != fa) {
        int16_t curmax = 0;
        for (int j = 1; j < r[now]; ++j) {
            if (tdec[0][j] != u) curmax = max(curmax, dpdec[tdec[0][j]][j]);
            else curmax = max(curmax, dpdec[tdec[1][j]][j]);
        }
        for (int j = r[now] + 1; j <= ds.size(); ++j) ans = max(ans, (int16_t)(dpinc[u][j] + 1 + curmax));
        curmax = 0;
        for (int j = r[now] + 1; j <= ds.size(); ++j) {
            if (tinc[0][j] != u) curmax = max(curmax, dpinc[tinc[0][j]][j]);
            else curmax = max(curmax, dpinc[tinc[1][j]][j]);
        }
        for (int j = 1; j < r[now]; ++j) ans = max(ans, (int16_t)(dpdec[u][j] + 1 + curmax));
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> r[i], ds.push_back(r[i]);
    sort(ds.begin(), ds.end()); ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 1; i <= n; ++i) r[i] = lower_bound(ds.begin(), ds.end(), r[i]) - ds.begin() + 1;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}