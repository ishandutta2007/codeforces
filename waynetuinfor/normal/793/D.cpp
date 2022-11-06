#include <bits/stdc++.h>
using namespace std;

const int maxn = 80 + 5, inf = 1e9 + 1;
int dp[maxn][maxn][maxn][maxn];
vector<pair<int, int>> G[maxn];

int go(int now, int l, int r, int k) {
    if (k <= 0) return 0;
    if (dp[now][l][r][k]) return dp[now][l][r][k];
    dp[now][l][r][k] = inf;
    for (auto i : G[now]) {
        if (i.first > now) {
            if (i.first < r) dp[now][l][r][k] = min(dp[now][l][r][k], go(i.first, now, r, k - 1) + i.second); 
        } else {
            if (i.first > l) dp[now][l][r][k] = min(dp[now][l][r][k], go(i.first, l, now, k - 1) + i.second);
        }
    }
    return dp[now][l][r][k];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    if (k == 1) return cout << "0" << endl, 0;
    int m; cin >> m;
    vector<pair<pair<int, int>, int>> edge;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
        edge.push_back(make_pair(make_pair(a, b), c));
    }
    int ans = inf;
    for (auto e : edge) {
        int l = 0, r = n + 1;
        if (e.first.second > e.first.first) l = e.first.first;
        else r = e.first.first;
        ans = min(ans, go(e.first.second, l, r, k - 2) + e.second); 
    }
    if (ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}