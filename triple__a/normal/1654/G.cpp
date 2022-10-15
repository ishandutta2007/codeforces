// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
// #define int long long
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
mt19937 rng(123);
int n,m;
int a[N],h[N],dist[N],ans[N];
vi g[N];
bool vis[N],sp[N];
vi cnt[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,n-1){
        int u,v;
        cin>>u>>v;
        u--, v--;
        g[u].pb(v), g[v].pb(u);
    }
    queue<int> q;
    rep(i,n) if (a[i]) q.push(i), vis[i]=1;
    while (sz(q)){
        int ret=q.front();
        q.pop();
        for (auto c:g[ret]) if (!vis[c]) vis[c]=1, h[c]=h[ret]+1, q.push(c);
    }
    rep(i,n) for (auto c:g[i]) if (h[c]==h[i]) sp[c]=sp[i]=1;
    rep(i,n) if (sp[i]) cnt[h[i]].pb(i);
    rep(i,n) ans[i]=h[i];
    rep(i,n+1) if (sz(cnt[i])){
        vi dist(n,INF);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for (auto c:cnt[i]) pq.push({0,c}), dist[c]=0;
        while (sz(pq)){
            auto [d,ret]=pq.top();
            pq.pop();
            for (auto c:g[ret]){
                if (h[c]<h[ret]) continue;
                if (h[c]==h[ret]) {
                    if (dist[c]>dist[ret]+1) dist[c]=dist[ret]+1, pq.push({dist[c],c});
                }
                else {
                    if (dist[c]>max(dist[ret]-1,0)) dist[c]=max(dist[ret]-1,0), pq.push({dist[c],c});
                }
            }
        }
        rep(j,n) if (!dist[j]) ans[j]=min(ans[j],i);
    }
    rep(i,n) cout<<2*h[i]-ans[i]<<" ";
    return 0;
}


/*
3 10
1 1
1 0
0 2
2 2
1 2
1 1
1 1
1 0
0 0
0 1
*/