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
int n, m, i, x[MN], y[MN], w[MN], f[MN], t[MN], ans[MN], d[MN];
vector<pii> adj[MN]; queue<int> q;

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=m;i++){
        scanf("%d%d%d",&x[i],&y[i],&w[i]);
        adj[x[i]].pb({y[i],i});
        adj[y[i]].pb({x[i],i});
        t[x[i]]+=w[i]; t[y[i]]+=w[i];
    }
    q.push(1); d[1]=1; t[n]=-1;
    while(q.size()){
        int c = q.front(); q.pop();
        for(auto v : adj[c]){
            if(d[v.first]) continue;
            f[v.first] += w[v.second];
            if(c!=x[v.second]) ans[v.second]=1;
            if(2*f[v.first]==t[v.first]){
                d[v.first]=1; q.push(v.first);
            }
        }
    }
    for(i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}