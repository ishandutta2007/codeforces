#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> graf[maxn];
int dp[maxn][2], v[maxn][2], to[maxn][2], pr[maxn];
bool ins[maxn], dr;

int dfs(int now, int p) {
    if (v[now][p] == 2 || dp[now][p]) return dp[now][p];
    if (graf[now].size() == 0 && p == 0) return 1;
    dp[now][p] = 0;
    ++v[now][p];
    ins[now] = true;
    for (int u : graf[now]) if (!ins[u]) {
        int t = dfs(u, p ^ 1);
        if (t == 1) dp[now][p] = 1, to[now][p] = u;
        if (ins[u]) dr = true;
    }
    for (int u : graf[now]) if (!dp[now][p] && ins[u]) {
        int t = dfs(u, p ^ 1);
        if (t == 1) dp[now][p] = 1, to[now][p] = u;
        if (ins[u]) dr = true;
    }
    ins[now] = false;
    return dp[now][p];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int c; cin >> c;
        while (c--) {
            int a; cin >> a;
            graf[i].push_back(a);
        }
    }
    int s; cin >> s;
    int ans = dfs(s, 1);
    if (ans == 0) {
        if (dr) cout << "Draw" << endl;
        else cout << "Lose" << endl;
        return 0;
    }
    int now = s, p = 1;
    cout << "Win" << endl;
    while (true) {
        cout << now << ' ';
        if (graf[now].size() == 0) break;
        now = to[now][p], p ^= 1;
    }
    cout << endl;
}