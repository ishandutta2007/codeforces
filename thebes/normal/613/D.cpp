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
int N, Q, K, i, x, y, vis[MN][2], nxt, sz[MN], lnk[MN], dep[MN], par[MN], dp[MN][2], ok[MN], fl;
vi vec, tin, adj[MN]; vector<pii> t[MN]; stack<int> st;

void dfs(int n,int p,int d){
    vis[n][0]=++nxt;
    par[n]=p; sz[n]=1;
    dep[n]=d;
    pii big(-1,-1);
    for(auto v : adj[n]){
        if(v==p) continue;
        dfs(v,n,d+1);
        sz[n]+=sz[v];
        if(sz[v]>big.first)big={sz[v],v};
    }
    if(big.second!=-1) lnk[big.second]=n;
    vis[n][1]=nxt;
}

void dfs2(int n,int p){
    if(!lnk[n]) lnk[n]=n;
    else lnk[n]=lnk[lnk[n]];
    for(auto v : adj[n]){
        if(v==p) continue;
        dfs2(v,n);
    }
}

inline bool con(int x,int y){return vis[x][0]<=vis[y][0]&&vis[x][1]>=vis[y][1];}
inline int lca(int x,int y){
    while(!con(lnk[x],y)) x=par[lnk[x]];
    while(!con(lnk[y],x)) y=par[lnk[y]];
    return con(x,y)?x:y;
}

void solve(int n){
    dp[n][0]=dp[n][1]=0;
    if(ok[n]){
        vi hm; int a=0, b=1;
        for(auto v : t[n]){
            solve(v.first);
            dp[n][1]=min(dp[n][1]+dp[v.first][0],dp[v.first][1]+a);
            a+=dp[v.first][0];
            b+=min(dp[v.first][0],dp[v.first][1]);
        }
        dp[n][0]=min(a,b);
    }
    else{
        dp[n][0]=1<<20;
        for(auto v : t[n]){
            solve(v.first);
            if(!v.second&&!ok[v.first]) fl=1;
            dp[n][1]+=min(dp[v.first][0],dp[v.first][1]+1);
        }
    }
}

int main(){
    scanf("%d",&N);
    for(i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0,1);
    dfs2(1,0);
    for(scanf("%d",&Q);Q;Q--){
        scanf("%d",&K);
        vec.clear();
        for(i=1;i<=K;i++){
            scanf("%d",&x);
            vec.pb(x);
        }
        sort(vec.begin(),vec.end(),[](int i,int j){return vis[i][0]<vis[j][0];});
        tin.clear();
        for(i=0;i+1<vec.size();i++)
            tin.pb(vec[i]),tin.pb(lca(vec[i],vec[i+1]));
        tin.pb(vec.back());
        sort(tin.begin(),tin.end(),[](int i,int j){return vis[i][0]<vis[j][0];});
        while(st.size()) st.pop();
        for(auto v : tin)
            ok[v]=1,t[v].clear();
        int prev=-1;
        for(auto v : tin){
            if(v==prev) continue;
            prev=v;
            while(st.size()){
                int id=st.top();
                if(vis[id][0]<=vis[v][0]&&vis[id][1]>=vis[v][1]) break;
                else st.pop();
            }
            if(st.size())
                t[st.top()].pb({v,dep[v]-dep[st.top()]-1});
            st.push(v);
        }
        for(auto v : vec)
            ok[v]=0;
        fl=0; solve(tin[0]);
        if(fl) printf("-1\n");
        else printf("%d\n",min(dp[tin[0]][0],dp[tin[0]][1]));
    }
    return 0;
}