// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
 
#define int long long
// #define i128 long long
#define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=998244353;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=200007;
const int K=18;
mt19937 rng(time(NULL));


int n;
int a[N],p[N],par[N],vis[N],q[N],siz[N];
vi g[N];
int fnd(int u){
    if (par[u]==u) return u;
    return par[u]=fnd(par[u]);
}

void unite(int u,int v){
    int pu=fnd(u), pv=fnd(v);
    if (pu==pv) return;
    par[pu]=pv, siz[pv]+=siz[pu];
}


signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        rep1(i,n) g[i].clear();
        rep1(i,n) cin>>a[i], g[a[i]].pb(i),par[i]=i, vis[i]=0, p[i]=0, siz[i]=1;
        int fk=0;
        rep1(i,n) {
            if (sz(g[i])&1) fk++;
        }
        if (fk>1){
            cout<<"NO\n";
            continue;
        }
        int cnt=1;
        rep1(i,n){
            int m=sz(g[i]);
            sort(range(g[i]),[&](int u,int v){return u==(n+1)/2||(v!=(n+1)/2&&u<v);});
            rep(j,m/2) p[cnt]=g[i][j], p[n+1-cnt]=g[i][m-1-j], cnt++;
            if (m&1) p[(n+1)/2]=g[i][m/2];
        }
        rep1(i,n) assert(p[i]);
        for (int i=1;i<=n;++i){
            if (vis[i]) continue;
            int now=i;
            while (1){
                vis[now]=1;
                unite(i,now);
                now=p[now];
                if (now==i) break;
            }
        }
        for (int i=1;i<=n/2;++i){
            if (fnd(i)!=fnd(n+1-i)) {
                unite(i,n+1-i);
                swap(p[i],p[n+1-i]);
            }
        }
        for (int i=1;i<n/2;++i){
            if (fnd(i)!=fnd(i+1)){
                swap(p[i],p[n-i]);
                swap(p[n-i],p[i+1]);
                swap(p[n-i],p[n-i+1]);
                unite(i,i+1);
            }
        }
        if (siz[fnd(1)]==n){
            cout<<"YES\n";
            rep1(i,n) cout<<p[i]<<" ";
            cout<<"\n";
        }
        else cout<<"NO\n";
        
    }
    return 0;
}


/*
10

*/