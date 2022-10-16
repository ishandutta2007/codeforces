#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

const int N = 5007;
const int MOD = 998244353;

int n, k, dp[N][N], s[N], d[N], id[N];
ll tmp[N];
vector<int> pl[N], pr[N];
vector<int> g[N];

void dfs(int v, int p = -1) {
    d[v] = 0;
    vector<int> sons;
    for (int to : g[v]) {
        if (to != p) sons.push_back(to);
        if (to != p) dfs(to, v), d[v] = max(d[v], d[to]+1);
    }

    for (int i = 0; i < sons.size(); ++i)
        id[sons[i]] = i;
    int m = sons.size();
    for (int h = 0; h <= d[v]; ++h) {
        pl[h].assign(m+1, 1);
        pr[h].assign(m+1, 1);
        for (int i = 0; i < m; ++i) {
            int to = sons[i];
            ll m = h ? dp[to][h-1] + s[to] : s[to];
            if (m >= MOD) m -= MOD;
            pl[h][i+1] = (ll)pl[h][i] * m % MOD;
        }
        for (int i = m; i--; ) {
            int to = sons[i];
            ll m = h ? dp[to][h-1] + s[to] : s[to];
            if (m >= MOD) m -= MOD;
            pr[h][i] = (ll)pr[h][i+1] * m % MOD;
        }
    }

    for (int h = 0; h <= d[v]; ++h) {
        int maxDeep = min(h, k/2) - 1;
        dp[v][h] = 1;
        for (int to : g[v]) {
            if (to == p) continue;
            ll m = s[to] + (maxDeep < 0 ? 0 : dp[to][maxDeep]);
            dp[v][h] = dp[v][h] * m % MOD;
        }
    }

    for (int to : g[v]) {
        fill(tmp, tmp+d[to]+1, 0);
        if (to == p) continue;
        int hmax = min(d[to], k-1);
        for (int j = k/2; j <= hmax; ++j) {
            int maxH = k - 1 - j;
            ll m = maxH ? dp[to][maxH-1] + s[to] : s[to];
            ll x = (ll) pl[maxH][id[to]] * pr[maxH][id[to]+1] % MOD;
            ll y = j ? dp[to][j] - dp[to][j-1] : dp[to][j];
            if (y < 0) y += MOD;
            tmp[j] = (tmp[j] + x*y) % MOD;
        }

        for (int j = 1; j <= d[to]; ++j) tmp[j] += tmp[j-1];
    
        for (int h = 0; h <= d[v]; ++h) {
            int hmin = k/2;
            int hmax = min(h-1, min(d[to], k-1));
            if (hmax < hmin) continue;
            ll add = tmp[hmax];
            if (hmin) add -= tmp[hmin-1];
            dp[v][h] = (dp[v][h] + add) % MOD;
        }
    }

    for (int h = d[v]+1; h <= n; ++h) 
        dp[v][h] = dp[v][h-1];
    s[v] = dp[v][n];
}

int main() {
    cin >>n >> k;
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    if (k) dfs(0);
    else s[0] = 1;
    cout << s[0] << endl;
}