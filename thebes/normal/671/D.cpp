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

const int MN = 3e5+5;
ll n, m, i, x, y, w, dep[MN], sz[MN], id[MN], nxt, fl, cost[MN], zero[MN];
vi adj[MN]; map<ll,ll> dp[MN]; vector<pll> ed[MN];

void init(ll n,ll p,ll d){
    dep[n]=d;
    for(auto v : adj[n]){
        if(v==p) continue;
        init(v,n,d-1);
    }
}

inline void ins(map<ll,ll>&mp,pll val){
    auto it = mp.lower_bound(val.first);
    if(it==mp.end()||it->second>val.second){
        if(it!=mp.begin()){
            it--;
            while(it->second>val.second){
                auto it2=it;
                if(it==mp.begin()){mp.erase(it); break;}
                else{it--; mp.erase(it2);}
            }
        }
        mp[val.first]=val.second;
    }
}

void solve(ll n,ll p){
    if(fl) return;
    sz[n]=ed[n].size();
    pll big(-1,-1);
    for(auto v : adj[n]){
        if(v==p) continue;
        solve(v,n);
        sz[n]+=sz[v];
        if(sz[v]>big.first) big={sz[v],v};
    }
    if(fl) return;
    if(big.second==-1) id[n]=++nxt;
    else{
        id[n]=id[big.second];
        auto it = dp[id[n]].lower_bound(dep[n]);
        if(it==dp[id[n]].end()){fl=1;return;}
        cost[n]=cost[big.second]+it->second-zero[big.second];
        zero[n]=it->second;
    }
    for(auto v : adj[n]){
        if(v==p||v==big.second) continue;
        auto sta = dp[id[v]].lower_bound(dep[n]);
        if(sta==dp[id[v]].end()){fl=1; return;}
        cost[n]+=cost[v]+sta->second-zero[v]; ll mn=sta->second;
        while(sta!=dp[id[v]].end()){
            ins(dp[id[n]],make_pair(sta->first,sta->second-mn+zero[n]));
            sta++;
        }
    }
    for(auto v : ed[n]){
        ins(dp[id[n]],make_pair(v.first,v.second+zero[n]));
    }
}

int main(){
    for(scanf("%lld%lld",&n,&m),i=1;i<n;i++){
        scanf("%lld%lld",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    init(1,0,n);
    for(i=1;i<=m;i++){
        scanf("%lld%lld%lld",&x,&y,&w);
        if(x==y) continue;
        ed[x].pb({dep[y],w});
    }
    if(n==1){
        printf("0\n");
        return 0;
    }
    solve(1,0);
    if(fl) printf("-1\n");
    else printf("%lld\n",cost[1]+dp[id[1]][dep[1]]-zero[1]);
    return 0;
}