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

const int MN = 2e5+5, LG = 20;
struct nd{int mn, cnt, lz;}st[3*MN];
int N, Q, i, j, x, y, vis[MN][2], nxt, dep[MN], sp[LG][MN];
vi adj[MN];
set<pii> s;

void dfs(int n,int p,int d){
    vis[n][0]=++nxt;
    sp[0][n]=p; dep[n]=d;
    for(auto v : adj[n]){
        if(v==p) continue;
        dfs(v, n, d+1);
    }
    vis[n][1]=nxt;
}

void build(int i,int s,int e){
    if(s!=e){
        build(2*i,s,(s+e)/2);
        build(2*i+1,(s+e)/2+1,e);
        st[i].cnt=e-s+1;
    }
    else st[i].cnt=1;
}

inline void upd_lz(int i,int s,int e){
    if(st[i].lz){
        st[i].mn+=st[i].lz;
        if(s!=e) st[2*i].lz+=st[i].lz, st[2*i+1].lz+=st[i].lz;
        st[i].lz=0;
    }
}

void upd(int i,int s,int e,int ss,int se,int val){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se) st[i].lz=val, upd_lz(i,s,e);
    else{
        if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,val),upd_lz(2*i,s,(s+e)/2);
        else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,val),upd_lz(2*i+1,(s+e)/2+1,e);
        else upd(2*i,s,(s+e)/2,ss,se,val),upd(2*i+1,(s+e)/2+1,e,ss,se,val);
        st[i].mn=min(st[2*i].mn,st[2*i+1].mn);
        st[i].cnt=(st[2*i].mn==st[i].mn?st[2*i].cnt:0)+(st[2*i+1].mn==st[i].mn?st[2*i+1].cnt:0);
    }
}

inline int adv(int x,int steps){
    for(int i=LG-1;i>=0;i--){
        if(steps&(1<<i))
            x=sp[i][x];
    }
    return x;
}

int main(){
    scanf("%d%d",&N,&Q);
    for(i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0,0);
    build(1,1,N);
    for(j=1;j<LG;j++){
        for(i=1;i<=N;i++)
            sp[j][i]=sp[j-1][sp[j-1][i]];
    }
    for(i=1;i<=Q;i++){
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        int coef = 1;
        if(s.count({x,y})){
            s.erase({x,y});
            coef = -1;
        }
        else s.insert({x,y});
        if(dep[x]>dep[y]) swap(x,y);
        if(vis[x][0]<=vis[y][0]&&vis[x][1]>=vis[y][1]){
            int ch = adv(y, dep[y]-dep[x]-1);
            upd(1,1,N,vis[ch][0],vis[ch][1],coef);
            upd(1,1,N,vis[y][0],vis[y][1],-coef);
        }
        else{
            upd(1,1,N,1,N,coef);
            upd(1,1,N,vis[x][0],vis[x][1],-coef);
            upd(1,1,N,vis[y][0],vis[y][1],-coef);
        }
        if(st[1].mn!=0) printf("0\n");
        else printf("%d\n",st[1].cnt);
    }
    return 0;
}