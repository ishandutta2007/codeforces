#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
vector<pair<int, char>> G[maxn];
int dp[maxn][maxn][2][27];
bool v[maxn][maxn][2][27];

int dfs(int i, int j, int t, int p) {
    if (v[i][j][t][p]) return dp[i][j][t][p];
    if (t == 0) {
        for (auto u : G[i]) {
            if (u.second - 'a' + 1 >= p) {
                int d = dfs(u.first, j, 1, max(p, u.second - 'a' + 1));
                if (d == 0) dp[i][j][t][p] = 1;
            }
        }
    } else {
        for (auto u : G[j]) {
            if (u.second - 'a' + 1 >= p) {
                int d = dfs(i, u.first, 0, max(p, u.second - 'a' + 1));
                if (d == 0) dp[i][j][t][p] = 1;
            }
        }
    }
    v[i][j][t][p] = true;
    return dp[i][j][t][p];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; char c; cin >> a >> b >> c;
        G[a].emplace_back(b, c);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dfs(i, j, 0, 0)) cout << 'A';
            else cout << 'B';
        }
        cout << endl;
    }
}