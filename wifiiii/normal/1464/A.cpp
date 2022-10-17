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

const int maxn = 100005;
int par[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}

int merge(int u,int v) {
    int x=find(u),y=find(v);
    if(x==y) return 1;
    par[x]=y;
    return 0;
}
vector<int> g[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=max(n,m);++i) par[i]=i,g[i].clear();
        int ans=0;
        for(int i=1;i<=m;++i) {
            int x,y;
            cin>>x>>y;
            if(x!=y) {
                g[x].push_back(i);
                g[y].push_back(i);
                ++ans;
            }
        }
        for(int i=1;i<=max(n,m);++i) {
            if(g[i].size()) {
                for(int j:g[i]) {
                    if(j!=g[i].back()) ans+=merge(j,g[i].back());
                }
            }
        }
        cout<<ans<<endl;
    }
}