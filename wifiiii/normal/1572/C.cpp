#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> lst(n), pre(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i], --a[i];
            pre[i] = lst[a[i]];
            lst[a[i]].push_back(i);
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<int(int,int)> dfs = [&](int l, int r) {
            if(l >= r) return 0;
            if(dp[l][r] != -1) return dp[l][r];
            int ret = dfs(l, r - 1) + 1;
            for(int k : pre[r]) {
                if(k >= l) {
                    ret = min(ret, dfs(l, k) + dfs(k + 1, r));
                }
            }
            return dp[l][r] = ret;
        };
        cout << dfs(0, n - 1) << '\n';
    }
}