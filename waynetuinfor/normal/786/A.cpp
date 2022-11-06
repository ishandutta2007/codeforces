#include <bits/stdc++.h>
using namespace std;

const int maxn = 7000 + 10;
int dp[2][maxn], n, tr[2][maxn];
// int w[2] = { 2, 1 }, l[2] = { 1, 2 };
vector<int> s[2];

void dfs(int p, int now) {
    // cout << "p = " << p << " now = " << now << endl;
    for (int u : s[p ^ 1]) {
        int to = (now - u < 1) ? now - u + n : now - u;
        // cout << "to = " << to << endl;
        if (dp[p ^ 1][to]) continue;
        if (dp[p][now] == 1) {
            dp[p ^ 1][to] = 2;
            dfs(p ^ 1, to);
        } else {
            ++tr[p ^ 1][to];
            if (tr[p ^ 1][to] == s[p ^ 1].size()) {
                dp[p ^ 1][to] = 1;
                dfs(p ^ 1, to);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < 2; ++i) {
        int k; cin >> k;
        s[i].resize(k);
        for (int j = 0; j < k; ++j) cin >> s[i][j];
    }
    dp[0][1] = dp[1][1] = 1;
    dfs(0, 1); dfs(1, 1);
    for (int i = 0; i < 2; ++i) {
        for (int j = 2; j <= n; ++j) cout << (dp[i][j] == 2 ? "Win" : dp[i][j] == 1 ? "Lose": "Loop") << ' ';
        cout << endl;
    }
    return 0;
}