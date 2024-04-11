// I believe this task appears somewhere before

// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
 
#define int long long
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
int n;
vi g[N],hh[N];
bool col[N];
void dfs(int u,int p){
    for (auto c:g[u]){
        if (c==p) continue;
        col[c]=col[u]^1;
        dfs(c,u);
    }
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        vi en; 
        cin>>n;
        rep(i,n) en.pb(i), en.pb(~i);
        rep(i,n+1) hh[i].clear(),g[i].clear(),col[i]=0;
        rep(i,n-1){
            int u,v;
            cin>>u>>v;
            u--, v--;
            g[u].pb(v), g[v].pb(u);
        }
        dfs(0,0);
        rep(i,n) {
            if (col[i]) cout<<sz(g[i])<<" ";
            else cout<<-sz(g[i])<<" ";
        }
    }
    return 0;
}


/*
10

*/