#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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


const int MN = 55;
const long double eps = 1e-7;
ll N, M, X, i, x, y, w, par[MN], cap[MN][MN]; long double lo, hi;
vector<pll> adj[MN]; vi g[MN]; queue<int> q;

inline void bfs(ll st){
    par[st]=0; q.push(st);
    while(q.size()){
        ll x = q.front(); q.pop();
        for(auto v : g[x]){
            if(par[v]==-1&&cap[x][v]>0){
                par[v]=x;
                q.push(v);
            }
        }
    }
}

int main(){
    scanf("%lld%lld%lld",&N,&M,&X);
    for(i=1;i<=M;i++){
        scanf("%lld%lld%lld",&x,&y,&w);
        adj[x].pb({y,w});
        g[x].pb(y);
        g[y].pb(x);
    }
    lo=0, hi=M*1e6;
    while(lo+eps<hi){
        long double m=(lo+hi)/2;
        memset(cap,0,sizeof(cap));
        memset(par,-1,sizeof(par));
        for(i=1;i<=N;i++){
            for(auto v : adj[i])
                cap[i][v.first]+=(v.second/m*X);
        }
        bfs(1);
        ll flow = 0;
        while(par[N]!=-1){
            ll cur = N, mn = 1<<30;
            while(par[cur]>0){
                ll pre = par[cur];
                mn=min(mn,cap[pre][cur]);
                cur=pre;
            }
            flow += mn;
            cur = N;
            while(par[cur]>0){
                ll pre = par[cur];
                cap[pre][cur]-=mn;
                cap[cur][pre]+=mn;
                cur=pre;
            }
            if(flow>=X) break;
            else{
                memset(par,-1,sizeof(par));
                bfs(1);
            }
        }
        if(flow>=X) lo=m+eps;
        else hi=m;
    }
    printf("%.8Lf\n",lo);
    return 0;
}