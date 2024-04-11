#include <bits/stdc++.h>
using namespace std;

namespace debug{
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
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T>
    void __(const set<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T,class T2>
    void __(const map<T,T2>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(make_pair(v.first,v.second)),_ffs=1;__("}");}
    void screm(){__("\n");}
    template<class T1,class... T2>
    void screm(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" | "),screm(t2...);else __("\n");}
    void pr(){__("\n");}
    template<class T1,class... T2>
    void pr(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),pr(t2...);else __("\n");}
}

using namespace debug;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 3005;
int N, i, j, x, y, par[MN][MN], sz[MN][MN]; ll dp[MN][MN], ans;
vi adj[MN];

void go(int n,int p,int rt){
    sz[rt][n] = 1; par[rt][n] = p;
    for(auto v : adj[n]){
        if(v==p) continue;
        go(v, n, rt);
        sz[rt][n] += sz[rt][v];
    }
}

ll solve(int x,int y){
    if(dp[x][y]!=-1) return dp[x][y];
    else if(par[x][y]==x) return 1LL*sz[x][y]*sz[y][x];
    dp[x][y]=max(solve(y,par[y][x]),solve(x,par[x][y]))+1LL*sz[x][y]*sz[y][x];
    return dp[x][y];
}

int main(){
    scanf("%d",&N);
    fox(i,1,N-1){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    fox(i,1,N) go(i,0,i);
    memset(dp,-1,sizeof(dp));
    fox(i,1,N){
        fox(j,1,N){
            if(i==j) continue;
            ans = max(ans, solve(i,j));
        }
    }
    printf("%lld\n",ans);
    return 0;
}