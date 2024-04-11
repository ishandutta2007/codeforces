#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int N=200050;
int n,a[N],dp[N],ans[N];
vector<int> E[N];

void DFS(int u,int p){
    dp[u]=a[u];
    for(int e:E[u])if(e!=p){
        DFS(e,u);
        dp[u]+=max(0,dp[e]);
    }
}

void DFS2(int u,int p){
    ans[u]=dp[u];
    for(int e:E[u])if(e!=p){
        dp[u]-=max(0,dp[e]);
        dp[e]+=max(0,dp[u]);
        DFS2(e,u);
        dp[e]-=max(0,dp[u]);
        dp[u]+=max(0,dp[e]);
    }
}

int main(){
    rd(n);
    for(int i=0;i<n;i++)rd(a[i]);
    for(int i=0;i<n;i++)if(!a[i])a[i]=-1;
    for(int i=1;i<n;i++){
        int u,v;rd(u,v);
        --u,--v;
        E[u].pb(v);
        E[v].pb(u);
    }
    DFS(0,-1);
    DFS2(0,-1);
    for(int i=0;i<n;i++)printf("%i ",ans[i]);
    return 0;
}