#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(n, -1)), s(2 * n, vector<ll>(2 * n));
    vector<vector<int>> rt(n, vector<int>(n));
    for(int i = 0; i < 2 * n; ++i) {
        ll tmp = 0;
        for(int j = i + 1; j < 2 * n; ++j) {
            for(int k = i; k < j; ++k) {
                tmp += a[k % n][j % n];
            }
            s[i][j] = tmp;
        }
    }
    ll tot = s[0][n - 1];
    function<ll(int,int)> solve = [&](int l, int r) -> ll {
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        if(l == r) {
            return dp[l][r] = tot - s[l][r] - s[r + 1][l - 1 + n];
        }
        ll ret = 1e18; int p = -1;
        for(int k = l; k <= r; ++k) {
            ll w = solve(l, k - 1) + solve(k + 1, r) + tot - s[l][r] - s[r + 1][l - 1 + n];
            if(w < ret) {
                ret = w;
                p = k;
            }
        }
        rt[l][r] = p;
        return dp[l][r] = ret;
    };
    solve(0, n - 1);
    vector<int> ans(n, -1);
    function<int(int,int)> dfs = [&](int l, int r) -> int {
        if(l > r) return -1;
        if(l == r) return l;
        int ls = dfs(l, rt[l][r] - 1), rs = dfs(rt[l][r] + 1, r);
        if(ls != -1) ans[ls] = rt[l][r];
        if(rs != -1) ans[rs] = rt[l][r];
        return rt[l][r];
    };
    dfs(0, n - 1);
    for(int i : ans) cout << i + 1 << ' '; cout << '\n';
}