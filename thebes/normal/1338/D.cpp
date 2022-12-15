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

const int MN = 1e5+5;
int N, i, x, y, sz[MN], ans, nxt, dp[MN][2];
vi adj[MN];

int dfs(int n,int p){
    sz[n]=1;
    for(auto v : adj[n]){
        if(v==p) continue;
        sz[n]+=dfs(v,n);
    }
    return sz[n];
}

void solve(int n,int p){
    ans=max(ans,(int)adj[n].size());
    vector<pii> a, b;
    for(auto v : adj[n]){
        if(v==p) continue;
        solve(v,n);
        b.pb({dp[v][0],v});
        a.pb({dp[v][1],v});
    }
    a.pb({0,-1}), a.pb({0,-2});
    b.pb({0,-1}), b.pb({0,-2});
    sort(a.begin(),a.end(),[](pii i,pii j){return i.first>j.first;});
    sort(b.begin(),b.end(),[](pii i,pii j){return i.first>j.first;});
    int sz=(int)adj[n].size()-(p!=0);
    dp[n][0]=max(0,max(sz-1+a[0].first,sz-1+b[0].first));
    dp[n][1]=max(0,max(b[0].first,a[0].first-1)+1);
    ans=max(ans,max(dp[n][0],dp[n][1]));
    ans=max(ans,(p!=0)+sz-2+b[0].first+b[1].first);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(a[i].second!=b[j].second)
                ans=max(ans,(p!=0)+sz-2+b[j].first+a[i].first);
        }
    }
    ans=max(ans,(p!=0)+sz-2+a[0].first+a[1].first);
    ans=max(ans,1+b[0].first+b[1].first);
}

int main(){
    for(scanf("%d",&N),i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0);
    solve(1,0);
    printf("%d\n",ans);
    return 0;
}