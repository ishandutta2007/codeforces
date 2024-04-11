#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        a[u] -= w;
        a[v] += w;
    }
    vector<ll> pos, neg;
    for(int i = 0; i < n; ++i) {
        if(a[i] > 0) pos.push_back(i);
        else if(a[i] < 0) neg.push_back(i);
    }
    vector<tuple<int,int,ll>> ans;
    while(!pos.empty() || !neg.empty()) {
        int x = pos.back(), y = neg.back();
        ll p = min(a[x], -a[y]);
        a[y] += p; a[x] -= p;
        if(!a[x]) pos.pop_back();
        if(!a[y]) neg.pop_back();
        ans.push_back({y, x, p});
    }
    cout << ans.size() << '\n';
    for(auto [u, v, w] : ans) {
        cout << u + 1 << " " << v + 1 << " " << w << '\n';
    }
}