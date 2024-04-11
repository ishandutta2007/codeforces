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
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=998244353;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=2007;
const int K=207;
mt19937 rng(time(NULL));

void dfs(vector<vector<pii>> &g,vi &val,int u,int col,bool &ok){
    val[u]=col;
    for (auto [v,x]:g[u]){
        if (val[v]!=-1){
            if (val[v]!=(col^x)) ok=0;
        }
        else{
            dfs(g,val,v,col^x,ok);
        }
    }
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    string s;
    cin>>s;
    int n=sz(s);
    if (s[n-1]=='1'){
        cout<<0;
        return 0;
    }
    int ans=0;
    rep1(l,n-1){
        vector<vector<pii>> g(2*n);
        vi val(2*n,-1);
        for (int i=1;i<n-l;++i){
            if (s[i]=='0') val[i]=0;
            else if (s[i]=='1') val[i]=1;
        }
        if (s[n-l]=='0') val[n-l]=1;
        else if (s[n-l]=='1') val[n-l]=0;
        for (int i=n-l+1;i<n;++i) {
            if (s[i]=='0') g[i].pb({i+n,0}), g[i+n].pb({i,0});
            else if (s[i]=='1') g[i].pb({i+n,1}), g[i+n].pb({i,1});
        }
        for (int i=1;i<n-1;++i) g[i].pb({n-1-i,0});
        for (int i=n-l+1;i<n-1;++i) g[n+i].pb({n+(n-2-(i-n+l-1)),0});
        // cerr<<"fk: "<<l<<endl;
        vi cand;
        for (int i=1;i<n-1;++i) cand.pb(i);
        for (int i=n-l+1;i<n-1;++i) cand.pb(n+i);
        // for (auto c:cand){
        //     cerr<<"ffk "<<c<<": ";
        //     for (auto [x,y]:g[c]) cerr<<x<<", "<<y<<" ; ";
        //     cerr<<endl;
        // }
        // for (auto c:cand) cerr<<val[c]<<" ";
        // cerr<<endl;
        bool ok=1;
        for (auto c:cand){
            if (val[c]==-1) continue;
            dfs(g,val,c,val[c],ok);
        }
        int cnt=0;
        for (auto c:cand){
            if (val[c]!=-1) continue;
            dfs(g,val,c,0,ok), cnt++;
        }
        if (!ok) continue;
        int tmp=1;
        for (int i=0;i<cnt;++i) tmp=tmp*2%mod;
        ans=(ans+tmp)%mod;
        // cerr<<ans<<endl;
    }
    cout<<ans;
    return 0;
}


/*
12 6
1 3
3 7
5 7
7 11
9 11
11 3

*/