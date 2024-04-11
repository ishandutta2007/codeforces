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


const int MN = 4e5+5;
int N, i, x, y, ok[MN], sz[MN], mx[MN], ct;
vi adj[MN]; map<int,int> mp;

int dfs(int n,int p){
    sz[n]=1; mx[n]=0;
    for(auto v : adj[n]){
        if(v==p) continue;
        sz[n] += dfs(v, n);
        mx[n] = max(mx[n],sz[v]);
    }
    mp[sz[n]]++;
    return sz[n];
}

void dfs2(int n,int p){
    if(2*mx[n]<=N&&2*(N-sz[n])<=N){
        ct = n;
    }
    for(auto v : adj[n]){
        if(v==p) continue;
        dfs2(v, n);
    }
}

void op(int n,int p,bool add=1){
    if(add) mp[sz[n]]++;
    else{mp[sz[n]]--; if(!mp[sz[n]])mp.erase(sz[n]);}
    for(auto v : adj[n]){
        if(v!=p) op(v,n,add);
    }
}

void dfs3(int n,int p){
    int rem = N-sz[n]-(N/2);
    auto it = mp.lower_bound(rem);
    if(it!=mp.end()&&it->first<=N/2) ok[n]=1;
    if(rem==0) ok[n]=1;
    mp[N-sz[n]]++;
    pii big(-1,-1);
    for(auto v : adj[n]){
        if(v==p) continue;
        if(sz[v]>big.first)
            big={sz[v],v};
    }
    for(auto v : adj[n]){
        if(v==p||v==big.second) continue;
        op(v,n);
    }
    if(big.second!=-1) dfs3(big.second,n);
    for(auto v : adj[n]){
        if(v==p||v==big.second) continue;
        op(v,n,0);
        dfs3(v,n);
    }
    mp[N-sz[n]]--;
    if(!mp[N-sz[n]]) mp.erase(N-sz[n]);
    mp[sz[n]]++;
}

int main(){
    scanf("%d",&N);
    for(i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0);
    dfs2(1,0);
    ok[ct]=1;
    mp.clear();
    dfs(ct,0);
    for(auto v : adj[ct]){
        op(v, ct, 0);
        dfs3(v, ct);
    }
    for(i=1;i<=N;i++)
        printf("%d ",ok[i]);
    printf("\n");
    return 0;
}