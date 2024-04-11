#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, K; cin >> N >> K;
        vector<vector<int>> adj(N+1);
        for (int i = 2; i <= N; ++i){
            int p; cin >> p;
            adj[p].push_back(i);
        }
        vector<ll> s(N+1);
        for (int i = 1; i <= N; ++i){
            cin >> s[i];
        }
        vector<unordered_map<int, ll>> cache(N+1);
        auto dfs = [&](auto self, int v, int k) -> ll{
            if (cache[v].count(k)) return cache[v][k];
            ll ans = k * s[v];
            int c = adj[v].size();
            if (c == 0){
                cache[v][k] = ans;
                return ans;
            }
            int rem = k % c;
            int nk = k / c;
            vector<ll> vals(c);
            for (int i = 0; i < c; ++i){
                ll tmp = self(self, adj[v][i], nk);
                ans += tmp;
                vals[i] -= tmp;
                if (rem) vals[i] += self(self, adj[v][i], nk+1);
            }
            if (rem){
                sort(vals.begin(), vals.end(), greater<ll>());
                for (int i = 0; i < rem; ++i){
                    ans += vals[i];
                }
            }
            cache[v][k] = ans;
            return ans;
        };
        cout << dfs(dfs, 1, K) << '\n';
    }
}