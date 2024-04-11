#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10;
int c[maxn], dp[maxn][maxn];
bool v[maxn][maxn];

int dfs(int l, int r) {
    if (l == r) return 1;
    if (l + 1 == r && c[l] == c[r]) return 1;
    if (v[l][r]) return dp[l][r];
    dp[l][r] = maxn + 1;
    if (c[l] == c[r]) dp[l][r] = dfs(l + 1, r - 1);
    for (int j = l; j < r; ++j) dp[l][r] = min(dp[l][r], dfs(l, j) + dfs(j + 1, r));
    v[l][r] = true;
    return dp[l][r];
}

int main() {
    srand(time(nullptr));
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i]; 
    cout << dfs(1, n) << endl;
    return 0;
}