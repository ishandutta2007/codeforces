#include <bits/stdc++.h>
using namespace std;

namespace debug{
    void __(short x){cout<<x;}
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

const int MN = 2e5+5;
int N, i, x, y, sz[MN], mx[MN], cc[MN], par[MN];
vi adj[MN], c; pii e;
struct op{int a, b, c;};
vector<op> ans;

int dfs1(int n,int p){
    sz[n] = 1;
    for(auto v : adj[n]){
        if(v==p) continue;
        int ss = dfs1(v, n);
        sz[n] += ss;
        mx[n] = max(mx[n], ss);
    }
    return sz[n];
}

void dfs2(int n,int p){
    if(2*mx[n]<=N&&2*(N-sz[n])<=N) cc[n]=1, c.pb(n);
    for(auto v : adj[n]){
        if(v==p) continue;
        dfs2(v, n);
    }
}

void solve(int n,int p,int r){
    if(p!=r){
        ans.pb({e.first,e.second,n});
        e.second = n;
        ans.pb({n,p,r});
    }
    for(auto v : adj[n]) if(v!=p) solve(v,n,r);
}

int main(){
    for(scanf("%d",&N),i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(auto cent : c){
        for(auto rt : adj[cent]){
            if(cc[rt]) continue;
            e = {cent, rt};
            for(auto v : adj[rt]) if(v!=cent) solve(v,rt,rt);
            ans.pb({e.first,e.second,rt});
        }
    }
    printf("%d\n",ans.size());
    for(auto v : ans) printf("%d %d %d\n",v.a,v.b,v.c);
    return 0;
}