#include <iostream>
#include <vector>

using namespace std;

const int MAXV = 300000;

int a[MAXV];
vector<int> path[MAXV];
pair<int, int> dp[MAXV];

void dfs(int v, int r) {
    dp[v] = make_pair(0, 0);
    if (a[v] == 1) ++dp[v].first;
    if (a[v] == 2) ++dp[v].second;

    for (int sv : path[v]) {
        if (sv == r) continue;
        dfs(sv, v);
        dp[v].first += dp[sv].first;
        dp[v].second += dp[sv].second;
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    dfs(0, -1);

    int ans = 0;
    for (int v = 0; v < N; ++v) {
        pair<int, int> par = make_pair(dp[0].first - dp[v].first, dp[0].second - dp[v].second);
        if (dp[v].first * dp[v].second == 0 && par.first * par.second == 0)
            ++ans;
    }

    cout << ans << endl;
    return 0;
}