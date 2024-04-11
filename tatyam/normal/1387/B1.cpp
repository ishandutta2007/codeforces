#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pll = pair<ll, ll>;
using tuplis = array<ll, 3>;
const ll LINF = 0x1fffffffffffffff;


int main(){
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for(ll i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll root = -1;
    for(ll i = 0; i < n; i++) if(g[i].size() == 1) root = i;
    vector<vector<ll>> child(n);
    auto dfs = [&](ll from, ll at, const auto& dfs) -> void {
        for(ll i : g[at]) if(i != from) dfs(at, i, dfs);
        if(child[at].empty()) child[from].push_back(at);
    };
    const ll x = g[root][0];
    dfs(root, x, dfs);
    ll sum = 0;
    vector<ll> ans(n);
    iota(ans.begin(), ans.end(), 0);
    if(child[root].empty()) child[x].push_back(root);
    for(ll i = 0; i < n; i++) if(child[i].size()){
        sum += child[i].size() * 2;
        for(ll j : child[i]) swap(ans[j], ans[i]);
    }
    cout << sum << endl;
    for(ll i = 0; i < n; i++) cout << ans[i] + 1 << " \n"[i + 1 == n];
}