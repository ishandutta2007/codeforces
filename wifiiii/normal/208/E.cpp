#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

vector<int> g[100005], rt;
vector<pair<int,int>> q[100005];
int sz[100005], son[100005], dep[100005], len[1000005], f[100005][18], ans[100005];
void dfs(int u,int fa) {
    sz[u]=1;
    for(int v:g[u]) {
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        f[v][0]=u;
        for(int i=1;i<=17;++i) f[v][i]=f[f[v][i-1]][i-1];
        dfs(v,u);
        if(len[son[u]] <= len[v]) son[u] = v;
        sz[u]+=sz[v];
    }
    len[u]=len[son[u]]+1;
}
int cnt[200005];
void add(int u,int fa){
    cnt[dep[u]]++;
    for(int v:g[u]) {
        if(v==fa) continue;
        add(v,u);
    }
}
void del(int u,int fa) {
    cnt[dep[u]]--;
    for(int v:g[u]) {
        if(v==fa) continue;
        del(v,u);
    }
}
void dfs2(int u,int fa,int keep) {
    for(int v:g[u]) {
        if(v==son[u] || v==fa) continue;
        dfs2(v,u,0);
    }
    if(son[u]) dfs2(son[u],u,1);
    cnt[dep[u]]++;
    for(int v:g[u]) if(v!=son[u] && v!=fa) add(v,u);
    for(auto p : q[u]) ans[p.second]=cnt[p.first+dep[u]];
    if(!keep)  {
        cnt[dep[u]]--;
        for(int v:g[u]) if(v!=fa) del(v,u);
    }
}

int L[100005], R[100005], dfn=0;
void dfs3(int u,int fa) {
    L[u]=++dfn,R[u]=L[u]+len[u]-1;
    if(son[u]) dfs3(son[u],u);
    for(int v:g[u]) {
        if(v==fa || v==son[u]) continue;
        dfs3(v,u);
    }
}
void dfs4(int u,int fa) {
    if(son[u]) dfs4(son[u],u);
    for(int v:g[u]) {
        if(v==fa || v==son[u]) continue;
        dfs4(v,u);
        for(int i=L[v];i<=R[v];++i) cnt[L[u]+i-L[v]+1] += cnt[i];
    }
    cnt[L[u]]++;
    for(auto p : q[u]) ans[p.second] = cnt[L[u]+p.first];
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) {
        int x;
        cin>>x;
        if(x) g[x].push_back(i);
        else rt.push_back(i);
    }
    for(int i:rt) dfs(i,0);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i) {
        int v,p;
        cin>>v>>p;
        for(int j=17;j>=0;--j) if(p>>j&1) v=f[v][j];
        if(!v) ans[i]=1;
        else q[v].push_back({p,i});
    }
    for(int i:rt) dfs3(i,0);
//    for(int i=1;i<=n;++i) {
//        cout << i << " : " << L[i] << " " << R[i] << " " << son[i] << endl;
//    }
    for(int i:rt) dfs4(i,0);
//    for(int i:rt) dfs2(i,0,0);
    for(int i=1;i<=t;++i) cout<<ans[i]-1<<" ";cout<<endl;
}