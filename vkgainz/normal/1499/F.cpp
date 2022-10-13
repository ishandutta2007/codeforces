#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int) x.size()

vector<vector<int>> adj;
vector<vector<long long>> dp;
vector<long long> num;
long long MOD = 998244353;

vector<long long> merge(vector<long long> a, vector<long long> b, int k, int idx_next) {
    vector<long long> ans(max(sz(a), sz(b) + 1), 0LL);
    for(int i = 0; i < sz(a); i++) {
        for(int j = 0; j < sz(b); j++) {
            if(i + j + 1 <= k)
                ans[max(i, j + 1)] += a[i] * 1LL * b[j];
            ans[max(i, j + 1)] %= MOD;
            if(i <= k)
                ans[max(i, 0)] += dp[idx_next][j] * 1LL * a[i];
            ans[max(i, 0)] %= MOD;
        }
    }
    return ans;
}

void dfs(int curr, int par, int &k) {
    vector<long long> bst = {1LL};
    for(int next : adj[curr]) {
        if(next == par) continue;
        dfs(next, curr, k);
        bst = merge(bst, dp[next], k, next);
    }
    dp[curr] = bst;
    num[curr] = accumulate(dp[curr].begin(), dp[curr].end(), 0LL) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    adj.resize(n);
    dp.resize(n);
    num.resize(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, k);
    if(num[0] < 0) num[0] += MOD;
    cout << num[0] << "\n";
}