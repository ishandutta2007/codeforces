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
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 2e5+5;
set<int> par[MN];
int n, m, k, i, x, y, arr[MN], vis[MN], dn[MN], dis[MN], a, b;
vi adj[MN]; queue<int> q;

void bfs(){
    int sz = q.size();
    while(sz--){
        x = q.front(); q.pop();
        dn[x] = 1;
        for(auto v : adj[x]){
            if(!vis[v]){
                vis[v] = 1; q.push(v);
                dis[v] = dis[x]+1;
            }
            if(dis[x]+1==dis[v]) par[v].insert(x);
        }
    }
    if(q.size()) bfs();
}

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        adj[y].pb(x);
    }
    for(scanf("%d",&k),i=1;i<=k;i++){
        scanf("%d",&arr[i]);
    }
    q.push(arr[k]);
    vis[arr[k]]=1;
    bfs();
    for(i=1;i<k;i++){
        int t = par[arr[i]].size();
        int h = 0;
        if(par[arr[i]].count(arr[i+1])) h = 1;
        if(t-h>0) b++;
    }
    for(i=1;i<k;i++){
        if(!par[arr[i]].count(arr[i+1])) a++;
    }
    printf("%d %d\n",a,b);
    return 0;
}