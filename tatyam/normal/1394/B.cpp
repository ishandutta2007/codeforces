#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;


int main(){
    mt19937_64 rng(58);
    ll n, m, k;
    cin >> n >> m >> k;
    
    vector<ull> hash_vertex(n);
    generate(hash_vertex.begin(), hash_vertex.end(), rng);
    vector hash_c(k, vector<ull>(k));
    ull hash_all = accumulate(hash_vertex.begin(), hash_vertex.end(), ull(0), bit_xor());
    
    vector<vector<pair<ll, ll>>> g(n);
    for(ll i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
    }
    
    for(auto& v : g){
        sort(v.begin(), v.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b){ return a.second < b.second; });
        for(ll i = 0; i < v.size(); i++) hash_c[v.size() - 1][i] ^= hash_vertex[v[i].first];
    }
    
    ll ans = 0;
    auto dfs = [&](ll at, ull hash, auto dfs) -> void {
        if(at == k){
            ans += hash == hash_all;
            return;
        }
        for(ll i = 0; i <= at; i++) dfs(at + 1, hash ^ hash_c[at][i], dfs);
    };
    dfs(0, 0, dfs);
    
    cout << ans << endl;
}