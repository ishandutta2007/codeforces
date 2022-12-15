#include <bits/stdc++.h>
using namespace std;

namespace debug{
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
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T>
    void __(const set<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T>
    void __(const multiset<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T,class T2>
    void __(const map<T,T2>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(make_pair(v.first,v.second)),_ffs=1;__("}");}
    void screm(){__("\n");}
    template<class T1,class... T2>
    void screm(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" | "),screm(t2...);else __("\n");}
    void pr(){__("\n");}
    template<class T1,class... T2>
    void pr(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),pr(t2...);else __("\n");}
}

using namespace debug;

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

const int MN = 1e5+5;
struct nd{int l, r, sm, fl;}st[100*MN];
int N, M, i, x, y, vis[MN][2], ans[MN], rt[MN], nxt;
vector<pii> ops[MN];
vi adj[MN];

int build(int s,int e){
    int cur = ++nxt;
    if(s!=e){
        st[cur].l=build(s,(s+e)/2);
        st[cur].r=build((s+e)/2+1,e);
    }
    return cur;
}

inline void upd_lz(int i,int s,int e){
    if(!i) return;
    if(st[i].fl){
        st[i].sm = e-s+1;
        if(st[i].l) st[st[i].l].fl=st[st[i].r].fl=1;
        st[i].fl = 0;
    }
}

inline bool done(int i,int s,int e){return !i||st[i].sm==e-s+1;}

int upd(int i,int s,int e,int ss,int se){
    if(!i) return i;
    upd_lz(i,s,e);
    if(done(i,s,e)) return i;
    int cur = ++nxt;
    if(s>=ss&&e<=se){
        st[cur].fl = 1;
        upd_lz(cur,s,e);
    }
    else{
        if((s+e)/2<ss){
            st[cur].r = upd(st[i].r,(s+e)/2+1,e,ss,se);
            st[cur].l = st[i].l;
            upd_lz(st[cur].l,s,e);
        }
        else if((s+e)/2>=se){
            st[cur].r = st[i].r;
            st[cur].l = upd(st[i].l,s,(s+e)/2,ss,se);
            upd_lz(st[cur].r,s,e);
        }
        else{
            st[cur].r = upd(st[i].r,(s+e)/2+1,e,ss,se);
            st[cur].l = upd(st[i].l,s,(s+e)/2,ss,se);
        }
        st[cur].sm = st[st[cur].l].sm+st[st[cur].r].sm;
    }
    return cur;
}

void ini(int n,int p){
    vis[n][0]=++nxt;
    for(auto v : adj[n]){
        if(v!=p) ini(v,n);
    }
    vis[n][1]=nxt;
}

void solve(int n,int p){
    if(n!=1) rt[n]=rt[p];
    for(auto v : ops[n]){
        rt[n]=upd(rt[n],1,N,vis[v.first][0],vis[v.first][1]);
        rt[n]=upd(rt[n],1,N,vis[v.second][0],vis[v.second][1]);
    }
    ans[n]=max(0,st[rt[n]].sm-1);
    for(auto v : adj[n])
        if(v!=p) solve(v,n);
}

int main(){
    scanf("%d%d",&N,&M);
    for(i=1;i<N;i++){
        scanf("%d%d",&x,&y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(i=1;i<=M;i++){
        scanf("%d%d",&x,&y);
        ops[x].pb({x,y});
        ops[y].pb({x,y});
    }
    ini(1,0);
    nxt = 0;
    rt[1] = build(1,N);
    solve(1,0);
    for(i=1;i<=N;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}