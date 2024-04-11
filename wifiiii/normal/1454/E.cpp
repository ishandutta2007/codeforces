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

const int maxn = 400005;
struct edge
{
    int v,nxt;
}es[maxn<<1];
int head[maxn], tot=1;
inline void adde(int u,int v){es[tot]=edge{v,head[u]}, head[u]=tot++;}
int fa[maxn],dfn[maxn],in[maxn],dfscnt=0,tp=0;
int lp[maxn];
void dfs1(int u) {
    dfn[u]=++dfscnt;
    for(int j=head[u];j;j=es[j].nxt) {
        int v=es[j].v;
        if(v==fa[u]) continue;
        if(dfn[v]) {
            if(dfn[v] < dfn[u]) continue;
            for(int x=v;x!=u;x=fa[x]) in[x]=1,lp[++tp]=x;
            in[u]=1,lp[++tp]=u;
        } else {
            fa[v]=u;
            dfs1(v);
        }
    }
}
int dfs2(int u,int f) {
    int ret = 1;
    for(int j=head[u];j;j=es[j].nxt) {
        int v = es[j].v;
        if(v == f || in[v]) continue;
        ret += dfs2(v, u);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=1;i<=n;++i) in[i]=dfn[i]=head[i]=0;
        tot=1;tp=0;dfscnt=0;
        for(int i=1;i<=n;++i) {
            int u,v;
            cin>>u>>v;
            adde(u,v);
            adde(v,u);
        }
        dfs1(1);
        ll ans=1ll*n*(n-1);
        for(int i=1;i<=tp;++i) {
            ll sz=dfs2(lp[i],-1);
            ans-=sz*(sz-1)/2;
        }
        cout<<ans<<endl;
    }
}