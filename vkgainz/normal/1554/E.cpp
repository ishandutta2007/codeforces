#include <bits/stdc++.h>
using namespace std;

#define rsz(x) x.clear(), x.resize(n)

vector<vector<int>> adj;
vector<int> num;
long long MOD = 998244353;

bool dfs(int curr, int par, int k) {
    for(int next : adj[curr]) {
        if(next == par) continue;
        if(!dfs(next, curr, k))
            return false;
    }
    if(par == -1)
        return num[curr] % k == 0;
    else {
        if(num[curr] % k == 0) {
            num[par]++;
            return true;
        }
        else if((num[curr] + 1) % k == 0) {
            return true;
        }
        else return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        rsz(adj);
        for(int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n + 1);
        vector<int> tau(n + 1);
        for(int i = 1; i <= n - 1; i++) {
            if((n - 1) % i == 0) {
                rsz(num);
                if(dfs(0, -1, i))
                    ans[i] = 1;
            }
        }
        long long tot = 1LL;
        for(int i = 1; i <= n - 1; i++)
            tot *= 2, tot %= MOD;
        tau[1] = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 2 * i; j < n; j += i)
                tau[j] -= tau[i];
        }
        int sub = 0;
        for(int i = 2; i < n; i++) {
            for(int j = 2 * i; j < n; j += i)
                ans[i] += tau[j / i] * ans[j];
            if(ans[i]) ++sub;
        }
        for(int i = 1; i <= n; i++) {
            if(i == 1) cout << (tot - sub + MOD) % MOD << " ";
            else cout << ans[i] << " ";
        }
        cout << "\n";

    }
}