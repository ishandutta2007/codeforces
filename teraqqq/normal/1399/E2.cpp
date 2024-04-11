#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using ll = long long;
 
void dfs(int v, int p, vector<vector<pair<int, pi>>> &g, vi &d, ll &sum, vector<ll> &s2, vector<ll> &s1){
    for(auto pr:g[v]){
        int u = pr.F; ll w = pr.S.F, c = pr.S.S;
        if(u == p)continue;
        dfs(u, v, g, d, sum, s2, s1);
        d[v] += d[u];
        sum += 1ll * w * d[u];
        while(w > 0){
            if(c == 1)s1.pb((w - w/2) * d[u]);
            else s2.pb((w - w/2) * d[u]);
            w >>= 1;
        }
    }
 
    if(g[v].size() == 1 && v)
        d[v] = 1;
}
 
void solve(){
    int n; ll S, sum = 0; cin >> n >> S;
    vector<vector<pair<int, pi>>> g(n);
    vi d(n);
    vector<ll> s1, s2;
    for(int i = 0; i < n - 1; ++i){
        ll u, v, w, c; cin >> u >> v >> w >> c;
        g[--u].pb({--v, {w, c}});
        g[v].pb({u, {w, c}});
    }
    dfs(0, -1, g, d, sum, s2, s1);
    sort(all(s1), [](ll a, ll b){return a > b;});
    sort(all(s2), [](ll a, ll b){return a > b;});
    vector<ll> ss1(s1.size()), ss2(s2.size());
    if(s1.size())ss1[0] = s1[0]; if(s2.size())ss2[0] = s2[0];
    for(int i = 1; i < max(s1.size(), s2.size()); ++i){
        if(i < s1.size())ss1[i] = s1[i] + ss1[i - 1];
        if(i < s2.size())ss2[i] = s2[i] + ss2[i - 1];
    }
    int k = 1e9;//cout << k << " ";
    for(int i = 0; i <= ss1.size(); ++i){
        ll pr = 0;
        if(i)pr = ss1[i - 1];
        int l = -1, r = ss2.size() + 1;
        int f = 0;
        while(l + 1 < r){
            int m = (l + r) >> 1;
            ll oao = (m ? ss2[m - 1] : 0);
            if(sum - (pr + oao) <= S)r = m, f = 1;
            else l = m;
        }
        //cout << i << " " << r << "\n";
        if(f)k = min(k, 2 * r + i);
    }
    cout << k << "\n";
    //for(auto x:d)cout << x << " ";cout << "\n";
}
 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while(n--)solve();
    return 0;
}