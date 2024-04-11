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

const int maxn = 300005;
int sz[maxn][3],a[maxn];
vi g[maxn];
void dfs(int u,int fa) {
    sz[u][a[u]]=1;
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        for(int i=0;i<=2;++i) sz[u][i]+=sz[v][i];
    }
}
int ans=0,tot[3];
void dfs2(int u,int fa) {
    for(int v:g[u]) {
        if(v==fa) continue;
        if((sz[v][2]==0 && sz[v][1]==tot[1]) || (sz[v][1]==0 && sz[v][2]==tot[2])) ++ans;
        dfs2(v,u);
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
    dfs(1,0);
    tot[2]=sz[1][2],tot[1]=sz[1][1];
    dfs2(1,0);
    cout<<ans<<endl;
}