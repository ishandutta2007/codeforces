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

const int MN = 2e5+5, LG = 20;
int N, M, i, j, par[MN], dep[MN], sp[LG][MN], vis[MN][2], nxt, x, y, w;
struct edge{int x, y, w;}; vector<edge> ed[MN];
vi adj[MN]; ll st[3*MN], lz[3*MN], dp[MN], g[MN];

void dfs(int n,int d){
    dep[n]=d;
    vis[n][0]=++nxt;
    for(auto v : adj[n])
        dfs(v, d+1);
    vis[n][1]=nxt;
}

inline int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(j=LG-1;j>=0;j--){
        if((1<<j)<=dep[x]-dep[y])
            x=sp[j][x];
    }
    if(x==y) return x;
    for(j=LG-1;j>=0;j--){
        if(sp[j][x]!=sp[j][y]){
            x=sp[j][x];
            y=sp[j][y];
        }
    }
    return sp[0][x];
}

inline void upd_lz(int i,int s,int e){
    if(lz[i]){
        st[i]+=1LL*(e-s+1)*lz[i];
        if(s!=e) lz[2*i]+=lz[i],lz[2*i+1]+=lz[i];
        lz[i]=0;
    }
}

void upd(int i,int s,int e,int ss,int se,int val){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se) lz[i]+=val, upd_lz(i,s,e);
    else{
        if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,val),upd_lz(2*i,s,(s+e)/2);
        else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,val),upd_lz(2*i+1,(s+e)/2+1,e);
        else upd(2*i,s,(s+e)/2,ss,se,val),upd(2*i+1,(s+e)/2+1,e,ss,se,val);
        st[i]=st[2*i]+st[2*i+1];
    }
}

ll qu(int i,int s,int e,int ind){
    upd_lz(i,s,e);
    if(s==e) return st[i];
    else if((s+e)/2<ind) return qu(2*i+1,(s+e)/2+1,e,ind);
    else return qu(2*i,s,(s+e)/2,ind);
}

void solve(int n){
    for(auto v : adj[n]){
        solve(v);
        g[n] += dp[v];
    }
    dp[n] = g[n];
    for(auto e : ed[n])
        dp[n]=max(dp[n],e.w+qu(1,1,N,vis[e.x][0])+qu(1,1,N,vis[e.y][0])+g[n]);
    upd(1,1,N,vis[n][0],vis[n][1],g[n]-dp[n]);
}

int main(){
    scanf("%d%d",&N,&M);
    for(i=2;i<=N;i++){
        scanf("%d",&par[i]);
        adj[par[i]].pb(i);
        sp[0][i]=par[i];
    }
    dfs(1,0);
    for(j=1;j<LG;j++){
        for(i=1;i<=N;i++)
            sp[j][i]=sp[j-1][sp[j-1][i]];
    }
    for(i=1;i<=M;i++){
        scanf("%d%d%d",&x,&y,&w);
        ed[lca(x,y)].pb({x,y,w});
    }
    solve(1);
    printf("%lld\n",dp[1]);
    return 0;
}