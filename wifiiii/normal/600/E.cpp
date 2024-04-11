#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e5+5;

int a[maxn];
vector<int> g[maxn];
int sz[maxn], son[maxn];
void dfs(int u, int fa) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[son[u]] < sz[v]) son[u] = v;
    }
}
ll ans[maxn];
int cnt[maxn];
ll cnt2[maxn];
ll cur = 0, mx = 0;
inline void ad(int u) {
    cnt2[cnt[a[u]]] -= a[u];
    cnt[a[u]]++;
    cnt2[cnt[a[u]]] += a[u];
    if(cnt[a[u]] > mx) {
        mx = cnt[a[u]];
        cur = a[u];
    } else if(cnt[a[u]] == mx) {
        cur = cnt2[cnt[a[u]]];
    }
}
inline void de(int u) {
    cnt2[cnt[a[u]]] -= a[u];
    cnt[a[u]]--;
    cnt2[cnt[a[u]]] += a[u];
    if(cnt[a[u]]+1 == mx) {
        if(cnt2[cnt[a[u]]+1]) cur = cnt2[cnt[a[u]]+1];
        else --mx, cur = cnt2[cnt[a[u]]];
    }
}
void add(int u, int fa) {
    ad(u);
    for(int v : g[u]) {
        if(v == fa) continue;
        add(v, u);
    }
}
void del(int u, int fa) {
    de(u);
    for(int v : g[u]) {
        if(v == fa) continue;
        del(v, u);
    }
}
void dfs2(int u, int fa, int keep) {
    for(int v : g[u]) {
        if(v == fa || v == son[u]) continue;
        dfs2(v, u, 0);
    }
    if(son[u]) dfs2(son[u], u, 1);
    ad(u);
    for(int v : g[u]) {
        if(v == fa || v == son[u]) continue;
        add(v, u);
    }
    ans[u] = cur;
    if(!keep) {
        de(u);
        for(int v : g[u]) {
            if(v == fa) continue;
            del(v, u);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;++i) cin>>a[i], cnt2[0]+=a[i];
    for(int i=1;i<n;++i) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    dfs2(1, -1, 1);
    for(int i=1;i<=n;++i) cout<<ans[i]<<" ";cout<<endl;
}