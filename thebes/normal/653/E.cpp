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
int n, m, k, i, j, x, y, mn, mx, fl;
set<int> adj[MN], nv;

void dfs(int n){
    if(!adj[n].count(1)) fl=1;
    vi go;
    for(auto v : nv){
        if(!adj[n].count(v)){
            go.pb(v);
        }
    }
    for(auto v : go) nv.erase(v);
    for(auto v : go) dfs(v);
}

int main(){
    for(scanf("%d%d%d",&n,&m,&k),i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        adj[x].insert(y);
        adj[y].insert(x);
    }
    mx = n-1-adj[1].size();
    for(i=2;i<=n;i++){
        nv.insert(i);
    }
    for(i=2;i<=n;i++){
        if(nv.count(i)){
            nv.erase(i);
            fl=0; dfs(i);
            mn++;
            if(!fl){
                printf("impossible\n");
                return 0;
            }
        }
    }
    printf("%s\n",(mn<=k&&k<=mx)?"possible":"impossible");
    return 0;
}