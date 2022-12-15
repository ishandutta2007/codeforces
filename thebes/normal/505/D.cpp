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

const int MN = 1e5+5;
int N, M, i, x, y, vis[MN][2], nxt, st[MN], cmp[MN], id, vs[MN], f, cnt;
set<int> hm, cc; vi adj[MN], wat[MN];
stack<int> s;

void dfs(int n){
    vis[n][0]=vis[n][1]=++nxt;
    st[n]=1; s.push(n);
    for(auto v : adj[n]){
        if(!vis[v][0]) dfs(v),vis[n][1]=min(vis[n][1],vis[v][1]);
        else if(st[v]) vis[n][1]=min(vis[n][1],vis[v][0]);
    }
    if(vis[n][0]==vis[n][1]){
        while(s.size()&&s.top()!=n){
            cmp[s.top()]=id+1; st[s.top()]=0;
            s.pop();
        }
        cmp[s.top()]=++id; st[s.top()]=0;
        s.pop();
    }
}

void ddfs(int n){
    vs[n] = 1; cnt++;
    if(cc.count(cmp[n])) f=1;
    cc.insert(cmp[n]);
    for(auto v : wat[n]){
        if(!vs[v]) ddfs(v);
    }
}

int main(){
    scanf("%d%d",&N,&M);
    for(i=1;i<=M;i++){
        scanf("%d%d",&x,&y);
        hm.insert(x), hm.insert(y);
        adj[x].pb(y);
        wat[x].pb(y);
        wat[y].pb(x);
    }
    for(i=1;i<=N;i++){
        if(!vis[i][0]) dfs(i);
    }
    int ans = 0;
    for(i=1;i<=N;i++){
        if(!vs[i]){
            f=cnt=0; ddfs(i);
            if(f) ans+=cnt;
            else ans+=cnt-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}