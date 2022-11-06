#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 10, inf = 1e9;
vector<pair<int, int>> grid[maxn * maxn];
int dp[2][maxn][maxn], last[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);    
    int n, m, p; cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int a; cin >> a; assert(a <= p);
            grid[a].emplace_back(i, j);
        }
    }
    int ans = inf;
    for (int now = 1; now <= p; ++now) {
        for (auto g : grid[now]) {
            int x, y; tie(x, y) = g;
            int dis = inf;
            for (int i = 1; i <= n; ++i) {
                if (last[i][y] == now - 1) dis = min(dis, dp[1][i][y] + abs(x - i));
            }
            dp[0][x][y] = (now == 1 ? abs(x - 1) + abs(y - 1) : dis);
            if (now == p) ans = min(ans, dis);
        }
        for (auto g : grid[now]) {
            int x, y; tie(x, y) = g;
            for (int i = 1; i <= m; ++i) {
                if (last[x][i] < now || last[x][i] == now && dp[0][x][y] + abs(y - i) < dp[1][x][i]) {
                    last[x][i] = now;
                    dp[1][x][i] = dp[0][x][y] + abs(y - i);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}