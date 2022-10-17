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

const int maxn = 200005;
int par[maxn],sz[maxn],szm[maxn],deg[maxn];
vi g[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
void merge(int u,int v) {
    int x=find(u),y=find(v);
    deg[u]++;deg[v]++;
    if(x==y) {
        szm[x]++;
        return;
    }
    par[x]=y;
    sz[y]+=sz[x];
    szm[y]+=szm[x]+1;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    ii par[i]=i,sz[i]=1;
    for(int i=1;i<=m;++i) {
        int u,v;
        cin>>u>>v;
        merge(u,v);
    }
    int ans=0;
    ii g[find(i)].pb(i);
    for(int i=1;i<=n;++i) {
        if(find(i)==i && sz[i]==szm[i] && sz[i]>2) {
            int ok=1;
            for(int j:g[i]) if(deg[j]!=2) ok=0;
            ans+=ok;
        }
    }
    cout<<ans<<endl;
}