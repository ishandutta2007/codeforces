#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)
#define F first
#define S second

const int MN = 3003;
int t, n, m, i, j, a[MN], b[MN], sz[MN], x, y;
vi adj[MN]; pll dp[MN][MN], tmp[MN];

void solve(int n,int p){
    sz[n]=1;
    dp[n][0]=make_pair(0,a[n]);
    for(auto v : adj[n]){
        if(v==p) continue;
        solve(v,n);
        for(int i=0;i<=min(m,sz[n]+sz[v]);i++)
            tmp[i]={-1,-1};
        for(int i=0;i<=min(m,sz[n]);i++){
            for(int j=0;j<=min(m-i,sz[v]);j++){
                if(dp[n][i].F+dp[v][j].F>tmp[i+j].F||(dp[n][i].F+dp[v][j].F==tmp[i+j].F&&dp[n][i].S+dp[v][j].S>tmp[i+j].S))
                    tmp[i+j]={dp[n][i].F+dp[v][j].F,dp[n][i].S+dp[v][j].S};
            }
        }
        sz[n]+=sz[v];
        for(int i=0;i<=min(m,sz[n]);i++)
            dp[n][i]=tmp[i];
    }
    for(int j=0;j<min(m,sz[n]);j++){
        if(dp[n][j].F+(dp[n][j].S>0)>dp[n][j+1].F||(dp[n][j].F+(dp[n][j].S>0)==dp[n][j+1].F&&dp[n][j+1].S<0))
            dp[n][j+1]={dp[n][j].F+(dp[n][j].S>0),0};
    }
}

int main(){
    for(scanf("%d",&t);t;t--){
        for(scanf("%d%d",&n,&m),i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]),a[i]-=b[i];
        for(i=1;i<=n;i++){
            adj[i].clear();
            for(j=0;j<=m;j++)
                dp[i][j]={-1,-1};
        }
        for(i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        solve(1,0);
        printf("%lld\n",dp[1][m-1].first+(dp[1][m-1].second>0));
    }
    return 0;
}