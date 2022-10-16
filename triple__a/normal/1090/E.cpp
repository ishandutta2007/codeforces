// how to come up with such solution :(

// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
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
 
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
const int mod=998244353;
const int INF=LLONG_MAX;
const double EPS=1e-9;
const int N=67;
const int K=207;
mt19937 rng(1234);

int n;
int par[N];
bool cont[N];
bool vis[N];
vector<pii> ans;
bool bfs(int now,int sgn){ // 0 - normal, 1 - abnormal
    memset(vis,0,sizeof(vis));
    memset(par,-1,sizeof(par));
    queue<int> q;
    q.push(now), vis[now]=1;
    while (sz(q)){
        int id=q.front();
        if (cont[id]){
            cont[id]=0;
            while (par[id]!=-1) ans.pb({id,par[id]}), id=par[id];
            return 1;
        }
        q.pop();
        int x=id%8, y=id/8;
        for (int i=0;i<8;++i){
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<0||nx>=8||ny<0||ny>=8) continue;
            if (sgn&&nx+ny*8>now) continue;
            if (!sgn&&nx+ny*8<now) continue;
            if (vis[nx+ny*8]) continue;
            q.push(nx+ny*8), vis[nx+ny*8]=1, par[nx+ny*8]=id;
        }
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n;
    for (int i=0;i<n;++i){
        string s;
        cin>>s;
        auto c0=s[0], c1=s[1];
        int to=(c0-'a')+(c1-'1')*8;
        cont[to]=1;
    }
    auto to_s=[&](int u){
        int x=u%8, y=u/8;
        cout<<(char)(x+'a')<<y+1;
    };  
    if (n>32) {
        for (int i=0;i<64;++i) cont[i]^=1;
        n=64-n;
        for (int i=0;i<n;++i) bfs(64-i-1,1);
        // reverse(range(ans));
        cout<<sz(ans)<<"\n";
        for (auto [u,v]:ans) to_s(v), cout<<"-", to_s(u), cout<<"\n";
        return 0;
    }
    for (int i=0;i<n;++i) bfs(i,0);
    cout<<sz(ans)<<"\n";
    for (auto [u,v]:ans) to_s(u), cout<<"-", to_s(v), cout<<"\n";
    return 0;
}

/*

*/