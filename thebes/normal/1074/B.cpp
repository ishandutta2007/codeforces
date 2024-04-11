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

const int MN = 1005;
int T, N, i, x, y, k, dep[MN], par[MN], ok[MN], rt;
vi a, b, adj[MN]; set<int> A, B;

inline int qu(char c,int x){
    printf("%c %d\n",c,x);
    fflush(stdout);
    int r; cin >> r; 
    if(r==-1) exit(0);
    return r;
}

void dfs(int n,int p,int d){
    par[n]=p; dep[n]=d;
    for(auto v : adj[n]){
        if(v==p) continue;
        dfs(v, n, d+1);
        ok[n] += ok[v];
    }
    if(rt==-1&&ok[n]==a.size()) rt=n;
}

inline void answer(int x){
    printf("C %d\n",x);
    fflush(stdout);
}

int main(){
    scanf("%d",&T);
    for(;T;T--){
        scanf("%d",&N);
        for(i=1;i<=N;i++)
            adj[i].clear();
        a.clear(); A.clear();
        b.clear(); B.clear();
        for(i=1;i<N;i++){
            scanf("%d%d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for(scanf("%d",&k),i=1;i<=k;i++){
            scanf("%d",&x);
            a.pb(x); A.insert(x);
        }
        for(scanf("%d",&k),i=1;i<=k;i++){
            scanf("%d",&x);
            b.pb(x); B.insert(x);
        }
        rt=-1;
        memset(ok,0,sizeof(ok));
        for(auto v : a)
            ok[v] = 1;
        dfs(1,0,0);
        int r=qu('A',rt);
        if(B.count(r)){
            answer(rt);
            continue;
        }
        int hm=qu('B',b[0]);
        if(A.count(hm)){
            answer(hm);
            continue;
        }
        while(hm&&!A.count(hm))
            hm=par[hm];
        if(!hm){
            answer(-1);
            continue;
        }
        int lst=qu('A',hm);
        if(B.count(lst)) answer(hm);
        else answer(-1);
    }
    return 0;
}