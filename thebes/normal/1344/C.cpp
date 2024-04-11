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

const int MN = 2e5+5;
int n, m, i, x, y, in[MN], vis[MN][2], vs[MN][2], st[MN], nxt, fl;
vi adj[MN], rev[MN]; stack<int> s; string ans;

void dfs(int n){
    vis[n][0]=vis[n][1]=++nxt;
    s.push(n); st[n]=1;
    for(auto v : adj[n]){
        if(!vis[v][0]) dfs(v), vis[n][1]=min(vis[v][1],vis[n][1]);
        else if(st[v]) vis[n][1]=min(vis[n][1],vis[v][0]);
    }
    if(vis[n][0]==vis[n][1]){
        if(s.empty()||s.top()!=n) fl=1;
        else s.pop(),st[n]=0;
    }
}

void go1(int n){
    vs[n][0] = 1;
    for(auto v : adj[n]){
        if(!vs[v][0]) go1(v);
    }
}

void go2(int n){
    vs[n][1] = 1;
    for(auto v: rev[n]){
        if(!vs[v][1]) go2(v);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        rev[y].pb(x);
    }
    for(i=1;i<=n;i++){
        if(!vis[i][0]) dfs(i);
    }
    if(fl) printf("-1\n");
    else{
        int cnt = 0;
        for(i=1;i<=n;i++){
            if(!vs[i][0]&&!vs[i][1]){
                cnt ++;
                ans += 'A';
            }
            else ans += 'E';
            go1(i), go2(i);
        }
        printf("%d\n%s\n",cnt,ans.c_str());
    }
    return 0;
}