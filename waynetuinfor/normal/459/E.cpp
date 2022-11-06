#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int dp[2][maxn];
vector<pair<int, int>> edge[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        edge[c].push_back(make_pair(a, b));
    }
    for (int i = 0; i < maxn; ++i) {
        for (auto e : edge[i]) dp[1][e.second] = 0;
        for (auto e : edge[i]) dp[1][e.second] = max(dp[1][e.second], dp[0][e.first] + 1);
        for (auto e : edge[i]) dp[0][e.second] = max(dp[0][e.second], dp[1][e.second]);
    } 
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[0][i]);
    cout << ans << endl;
    return 0;
}