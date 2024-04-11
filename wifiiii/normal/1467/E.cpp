#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int maxn = 200005;
int a[maxn];
vector<int> g[maxn];
int sz[maxn], son[maxn], tot[maxn], cnt[maxn], tag[maxn], val[maxn], all=0;

void dfs(int u, int fa) {
    sz[u] = 1; tot[a[u]]++;
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[son[u]]<sz[v]) son[u]=v;
    }
}

void add(int u, int fa, int x) {
    cnt[a[u]] += x;
    for(int v : g[u]) {
        if(v == fa) continue;
        add(v, u, x);
    }
}
int ok = 1;
void dfs2(int u, int fa, int keep) {
    if(!ok) return;
    for(int v : g[u]) {
        if(v == fa || v == son[u]) continue;
        dfs2(v, u, 0);
    }
    int del = 0;
    if(son[u]) {
        int pre = cnt[a[u]];
        dfs2(son[u], u, 1);
        if(tot[a[u]] > 1 && cnt[a[u]] - pre > 0) {
            if(cnt[a[u]] - pre == tot[a[u]] - 1) {
                assert(del == 0);
                del = 1;
                // delete all except this subtree
                tag[son[u]]--;
                all++;
            } else {
                ok = 0;
                return;
            }
        }
    }
    for(int v : g[u]) {
        if(v == fa || v == son[u]) continue;
        int pre = cnt[a[u]];
        add(v, u, 1);
        if(tot[a[u]] > 1 && cnt[a[u]] - pre > 0) {
            if(cnt[a[u]] - pre == tot[a[u]] - 1) {
                assert(del == 0);
                del = 1;
                // delete all except this subtree
                tag[v]--;
                all++;
            } else {
                ok = 0;
                return;
            }
        }
    }
    if(tot[a[u]] > 1 && !del) {
        // delete this subtree
        tag[u]++;
    }
    cnt[a[u]]++;
    if(!keep) {
        for(int v : g[u]) {
            if(v == fa) continue;
            add(v, u, -1);
        }
        cnt[a[u]]--;
    }
}

void dfs3(int u, int fa, int cur) {
    val[u] = all + cur + tag[u];
    assert(val[u] >= 0);
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs3(v, u, cur + tag[u]);
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<n;++i) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> aa;
    for(int i=1;i<=n;++i) aa.push_back(a[i]);
    sort(aa.begin(),aa.end());
    aa.resize(unique(aa.begin(),aa.end())-aa.begin());
    for(int i=1;i<=n;++i) a[i]=lower_bound(aa.begin(),aa.end(),a[i])-aa.begin()+1;
    dfs(1,0);
    dfs2(1,0,1);
    if(!ok) {
        cout<<0<<endl;
        return 0;
    }
    dfs3(1,0,0);
    int ans=0;
    for(int i=1;i<=n;++i) if(val[i]==0) ++ans;
    cout << ans << endl;
}