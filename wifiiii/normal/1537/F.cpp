#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5+5;
vector<int> g[maxn];
int color[maxn], vis[maxn], flag = 1;
void dfs(int u, int c) {
    vis[u] = 1;
    color[u] = c;
    for(int v : g[u]) {
        if(vis[v]) {
            if(color[v] == c) flag = 0;
            continue;
        }
        dfs(v, c ^ 1);
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n+1), b(n+1);
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=1;i<=n;++i) cin>>b[i];
        ll s1=accumulate(a.begin(),a.end(),0ll);
        ll s2=accumulate(b.begin(),b.end(),0ll);
        for(int i=1;i<=n;++i) g[i].clear();
        for(int i=1;i<=m;++i) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if((s1%2+2)%2 != (s2%2+2)%2) {
            cout << "NO\n";
            continue;
        }
        flag=1;
        for(int i=1;i<=n;++i) vis[i]=color[i]=0;
        dfs(1,0);
        if(flag) {
            ll s=0;
            for(int i=1;i<=n;++i) {
                if(color[i] == 0) {
                    s += a[i];
                    s -= b[i];
                } else {
                    s -= a[i];
                    s += b[i];
                }
            }
            cout << (s ? "NO" : "YES") << '\n';
        } else {
            cout << "YES\n";
        }
    }
}