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
#define fox(i,x,y) for(int i=(x);i<=(y);i++)

const int MN = 1e5+5, MM = 9e5+5;
vector<pll> adj[MM];
ll n, m, s, i, j, x, y, l, r, w, dis[MM];
struct pq{bool operator()(const pll&i,const pll&j){return i.second>j.second;}};
priority_queue<pll,vector<pll>,pq> q;

void init(ll i,ll s,ll e){
    if(s!=e){
        init(2*i,s,(s+e)/2); init(2*i+1,(s+e)/2+1,e);
        adj[2*i+n].pb({i+n,0}); adj[2*i+1+n].pb({i+n,0});
        adj[i+5*n].pb({2*i+5*n,0}); adj[i+5*n].pb({2*i+1+5*n,0});
    }
    else adj[s].pb({i+n,0}), adj[i+5*n].pb({s,0});
}

void upd(ll i,ll s,ll e,ll ss,ll se,ll src,ll w,ll t){
    if(s>=ss&&e<=se){
        if(t==2) adj[src].pb({i+5*n,w});
        else adj[i+n].pb({src,w});
    }
    else if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,src,w,t);
    else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,src,w,t);
    else upd(2*i+1,(s+e)/2+1,e,ss,se,src,w,t),upd(2*i,s,(s+e)/2,ss,se,src,w,t);
}

int main(){
    scanf("%lld%lld%lld",&n,&m,&s);
    init(1,1,n);
    fox(i,1,m){
        scanf("%lld%lld%lld%lld",&j,&x,&l,&r);
        if(j==1) adj[x].pb({l,r});
        else scanf("%lld",&w), upd(1,1,n,l,r,x,w,j);
    }
    q.push({s,0});
    memset(dis,-1,sizeof(dis));
    while(q.size()){
        pll c = q.top(); q.pop();
        if(dis[c.first]!=-1) continue;
        dis[c.first]=c.second;
        for(auto v : adj[c.first])
           q.push({v.first,v.second+c.second});
    }
    fox(i,1,n) printf("%lld ",dis[i]);
    printf("\n");
    return 0;
}