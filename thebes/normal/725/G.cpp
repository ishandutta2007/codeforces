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
int N, M, i, j, x, y, t, sz[MN], lnk[MN], dep[MN], par[MN], idx[MN], rev[MN], nxt, ans[MN];
vi adj[MN]; struct qur{int x, y, id;}q[MN];
struct nd{int mx; pii lz;}st[3*MN];

void dfs(int n){
    sz[n] = 1;
    pii big(-1, -1);
    for(auto v : adj[n]){
        dep[v] = dep[n]+1;
        par[v] = n;
        dfs(v);
        sz[n] += sz[v];
        if(sz[v]>big.F) big={sz[v],v};
    }
    if(big.second!=-1)
        lnk[big.second]=n;
}

void dfs2(int n){
    if(lnk[n]==-1) lnk[n]=n, idx[n]=++nxt, rev[nxt]=n;
    else lnk[n]=lnk[lnk[n]], idx[n]=++nxt, rev[nxt]=n;
    int hmm = -1;
    for(auto v : adj[n]){
        if(lnk[v]==n){
            dfs2(v);
            hmm = v;
            break;
        }
    }
    for(auto v : adj[n]){
        if(v!=hmm) dfs2(v);
    }
}

inline void upd_lz(int i,int s,int e){
    if(st[i].lz.F||st[i].lz.S){
        st[i].mx=st[i].lz.S+(e-s)*st[i].lz.F;
        if(s!=e){
            st[2*i].lz=st[i].lz;
            st[2*i+1].lz={st[i].lz.F,st[i].lz.S+((s+e)/2+1-s)*st[i].lz.F};
        }
        st[i].lz={0,0};
    }
}

void upd(int i,int s,int e,int ss,int se,pii ln){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se) st[i].lz=ln, upd_lz(i,s,e);
    else{
        if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,ln), upd_lz(2*i,s,(s+e)/2);
        else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,ln), upd_lz(2*i+1,(s+e)/2+1,e);
        else upd(2*i,s,(s+e)/2,ss,se,ln), upd(2*i+1,(s+e)/2+1,e,ss,se,make_pair(ln.F,ln.S+ln.F*((s+e)/2+1-max(s,ss))));
        st[i].mx=max(st[2*i].mx,st[2*i+1].mx);
    }
}

int qu(int i,int s,int e,int ss,int se){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se) return st[i].mx;
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else return max(qu(2*i,s,(s+e)/2,ss,se),qu(2*i+1,(s+e)/2+1,e,ss,se));
}

int qu2(int i,int s,int e,int ss,int se,int val){
    upd_lz(i,s,e);
    if(e<ss||s>se) return -1;
    else if(s>=ss&&e<=se){
        if(s==e&&st[i].mx>val) return s;
        else if(st[i].mx<=val) return -1;
    }
    else if((s+e)/2<ss) return qu2(2*i+1,(s+e)/2+1,e,ss,se,val);
    else if((s+e)/2>=se) return qu2(2*i,s,(s+e)/2,ss,se,val);
    int res = qu2(2*i+1,(s+e)/2+1,e,ss,se,val);
    if(res!=-1) return res;
    return qu2(2*i,s,(s+e)/2,ss,se,val);
}

int main(){
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++){
        scanf("%d",&x);
        adj[x].pb(i);
    }
    memset(lnk,-1,sizeof(lnk));
    par[0] = -1;
    dfs(0); dfs2(0);
    for(i=1;i<=M;i++){
        scanf("%d%d",&q[i].x,&q[i].y);
        q[i].id = i;
        q[i].y += dep[q[i].x];
    }
    sort(q+1,q+M+1,[](qur i,qur j){return i.y==j.y?i.x<j.x:i.y<j.y;});
    for(i=1;i<=M;i++){
        x=q[i].x, t=q[i].y;
        vector<pii> chn;
        while(x!=-1){
            y = lnk[x];
            if(qu(1,1,nxt,idx[y],idx[x])>t){ // blocked
                int b = rev[qu2(1,1,nxt,idx[y],idx[x],t)];
                if(x!=b) chn.pb({idx[b]+1, idx[x]});
                break;
            }
            chn.pb({idx[y], idx[x]});
            x = par[y];
        }
        if(chn.empty()) ans[q[i].id]=q[i].y-dep[q[i].x];
        else if(x==-1){
            int tt = q[i].y;
            ans[q[i].id] = tt+dep[q[i].x];
            reverse(chn.begin(),chn.end());
            for(auto v : chn){
                upd(1,1,nxt,v.F,v.S,make_pair(2,tt));
                tt += 2*(v.S-v.F+1);
            }
        }
        else{
            reverse(chn.begin(),chn.end());
            x = rev[chn[0].F];
            ans[q[i].id] = q[i].y+dep[q[i].x]-2*dep[x]+2;
            int tt = q[i].y+2;
            for(auto v : chn){
                upd(1,1,nxt,v.F,v.S,make_pair(2,tt));
                tt += 2*(v.S-v.F+1);
            }
        }
    }
    for(i=1;i<=M;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}