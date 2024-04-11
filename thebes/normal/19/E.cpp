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

const int MN = 1e4+5;
int n, m, i, x, y, dep[MN], vs[MN], ps[MN], cnt;
struct edge{int x, y, id;}; vector<edge> ed, bad;
vector<pii> adj[MN], t[MN]; vi ans; pii par[MN];

void dfs(int n,int p,int d){
    dep[n] = d; vs[n] = 1;
    for(auto v : adj[n]){
        if(v.F==p) continue;
        if(vs[v.F]&&dep[v.F]<dep[n]) ed.pb({n, v.F, v.S});
        if(!vs[v.F]){
            dfs(v.F, n, d+1);
            t[n].pb(v);
            par[v.F]={n,v.S};
        }
    }
}

void acc(int n,int k){
    for(auto v : t[n]){
        acc(v.F, k);
        ps[n] += ps[v.F];
    }
    if(ps[n]==k)
        ans.pb(par[n].S);
}

int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb({y,i});
        adj[y].pb({x,i});
    }
    for(i=1;i<=n;i++){
        if(vs[i]) continue;
        ed.clear();
        dfs(i, 0, 0);
        bad.clear();
        for(auto v : ed){
            if(dep[v.x]%2==dep[v.y]%2){
                bad.pb(v);
                x=v.x, y=v.y;
                if(dep[x]<dep[y]) swap(x,y);
                ps[x]++, ps[y]--;
            }
            else{
                x=v.x, y=v.y;
                if(dep[x]<dep[y]) swap(x,y);
                ps[x]--, ps[y]++;
            }
        }
        if(bad.empty()) continue;
        cnt ++;
        int pre = ans.size();
        if(bad.size()==1) ans.pb(bad[0].id);
        acc(i, bad.size());
        if(pre==ans.size()) cnt += 1000;
    }
    sort(ans.begin(),ans.end());
    if(cnt>1) printf("0\n");
    else if(!cnt){printf("%d\n",m); for(i=1;i<=m;i++) printf("%d ",i); printf("\n");}
    else{printf("%d\n",ans.size()); for(auto v : ans) printf("%d ",v); printf("\n");}
    return 0;
}