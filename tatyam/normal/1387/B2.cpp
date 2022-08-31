#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pll = pair<ll, ll>;
using tuplis = array<ll, 3>;
const ll LINF = 0x1fffffffffffffff;
template<class T, class U> bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }


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
    ll root = -1, root2 = -1, min = LINF;
    vector<ll> siz(n, 1);
    auto dfs = [&](ll from, ll at, const auto& dfs) -> void {
        for(ll i : g[at]) if(i != from){
            dfs(at, i, dfs);
            siz[at] += siz[i];
        }
        if(siz[at] * 2 > n && chmin(min, siz[at])) root = at;
        else if(siz[at] * 2 < n && chmin(min, n - siz[at])) root = from;
        else if(siz[at] * 2 == n){
            root = at;
            root2 = from;
            min = n / 2;
        }
    };
    dfs(-1, 0, dfs);
    vector<ll> depth(n);
    ll sum = 0;
    vector<ll> idx, val;
    if(root2 == -1){
        auto dfs2 = [&](ll from, ll at, const auto& dfs2) -> void {
            for(ll i : g[at]) if(i != from){
                depth[i] = depth[at] + 1;
                idx.push_back(i);
                val.push_back(i);
                dfs2(at, i, dfs2);
            }
            sum += depth[at] * 2;
        };
        dfs2(-1, root, dfs2);
        idx.push_back(root);
        val.push_back(root);
    }
    else{
        vector<ll> depth2(n);
        auto dfs2 = [&](ll from, ll at, const auto& dfs2) -> void {
            for(ll i : g[at]) if(i != from){
                depth[i] = depth[at] + 1;
                dfs2(at, i, dfs2);
            }
            sum += depth[at] * 2;
        };
        dfs2(-1, root, dfs2);
        auto dfs3 = [&](ll from, ll at, const auto& dfs3) -> void {
            for(ll i : g[at]) if(i != from){
                depth2[i] = depth2[at] + 1;
                dfs3(at, i, dfs3);
            }
        };
        dfs3(-1, root2, dfs3);
        for(ll i = 0; i < n; i++) if(depth[i] < depth2[i]){
            idx.push_back(i);
            val.push_back(i);
        }
        for(ll i = 0; i < n; i++) if(depth[i] > depth2[i]){
            idx.push_back(i);
            val.push_back(i);
        }
    }
    rotate(val.begin(), val.begin() + val.size() / 2, val.end());
    vector<ll> ans(n);
    iota(ans.begin(), ans.end(), 0);
    for(ll i = 0; i < val.size(); i++) ans[idx[i]] = val[i];
    cout << sum << endl;
    for(ll i = 0; i < n; i++) cout << ans[i] + 1 << " \n"[i + 1 == n];
}