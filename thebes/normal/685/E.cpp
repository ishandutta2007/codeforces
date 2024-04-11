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


const int MN = 1005, MM = 2e5+5;
int N, M, Q, i, x, y, l, r, ans[MM];
struct qur{int x, y, l, r, id;}; vector<qur> vec;
vector<pii> adj[MN]; bitset<MN> msk[MN], dp[MM];
set<int> pos[MM]; pii ed[MM];

void solve(int l,int r,vector<qur> vec){
    if(vec.empty()) return;
    int mid = (l+r)>>1;
    vector<qur> lef, rit, go;
    for(auto v : vec){
        if(v.l>v.r) continue;
        if(v.r<mid) lef.pb(v);
        else if(v.l>mid) rit.pb(v);
        else go.pb(v);
    }
    solve(l,mid,lef);
    solve(mid+1,r,rit);
    for(i=mid;i<=r;i++){
        msk[ed[i].F].reset();
        msk[ed[i].S].reset();
        msk[ed[i].F][ed[i].F]=1;
        msk[ed[i].S][ed[i].S]=1;
    }
    for(i=mid;i<=r;i++){
        msk[ed[i].F]|=msk[ed[i].S];
        msk[ed[i].S]|=msk[ed[i].F];
        dp[i]=msk[ed[i].F];
    }
    for(i=mid;i>=l;i--){
        msk[ed[i].F].reset();
        msk[ed[i].S].reset();
        msk[ed[i].F][ed[i].F]=1;
        msk[ed[i].S][ed[i].S]=1;
    }
    for(i=mid;i>=l;i--){
        msk[ed[i].F]|=msk[ed[i].S];
        msk[ed[i].S]|=msk[ed[i].F];
        dp[i]=msk[ed[i].F];
    }
    for(auto v : go)
        ans[v.id]=(dp[v.l]&dp[v.r]).count();
}

int main(){
    scanf("%d%d%d",&N,&M,&Q);
    for(i=1;i<=M;i++){
        scanf("%d%d",&x,&y);
        pos[x].insert(i);
        pos[y].insert(i);
        adj[x].pb({y,i});
        adj[y].pb({x,i});
        ed[i]={x,y};
    }
    for(i=1;i<=Q;i++){
        scanf("%d%d%d%d",&l,&r,&x,&y);
        vec.pb({x,y,l,r,i});
    }
    for(i=0;i<Q;i++){
        auto it=pos[vec[i].x].lower_bound(vec[i].l);
        if(it==pos[vec[i].x].end()) vec[i].l=M+1;
        else vec[i].l=*it;
        it=pos[vec[i].y].upper_bound(vec[i].r);
        if(it==pos[vec[i].y].begin()) vec[i].r=0;
        else{it--; vec[i].r=*it;}
    }
    solve(1,M,vec);
    for(i=1;i<=Q;i++)
        printf("%s\n",ans[i]>0?"Yes":"No");
    return 0;
}