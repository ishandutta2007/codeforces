#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

const int maxn = 100105;

template<class T, T(*OP)(T,T), const T& low>
struct ST{
    int n;
    T t[maxn*2];
    ST(int nn):n(nn){}
    void build(){for(int i=n-1;i>0;--i) t[i] = OP(t[i<<1],t[i<<1|1]);}
    void modify(int p, T val){for(t[p+=n]=val;p>>=1;) t[p] = OP(t[p<<1],t[p<<1|1]);}
    T query(int l, int r){
        T resl=low, resr=low;
        for(l+=n,r+=n; l<r; l>>=1,r>>=1){
            if(l&1) resl = OP(resl,t[l++]);
            if(r&1) resr = OP(t[--r],resr);
        }
        return OP(resl,resr);
    }
};

typedef vi* graph;
template<class T, T(*OP)(T,T), const T& low>
struct HLD{
    const int n;
    int par[maxn],depth[maxn],heavy[maxn],pos[maxn],rt[maxn];
    ST<T,OP,low> tr; 
    const graph g;
    HLD(int nn, graph gg, T def):n(nn),tr(nn),g(gg){
        fill(heavy,heavy+n,-1);
        rep(i,0,n)tr.t[i+n]=def;
        tr.build();
        depth[0] = 0;
        dfs(0,-1);
        int tpos = 0;
        rep(i,0,n){
            if(par[i] == -1 || heavy[par[i]] != i)
                for(int j=i;j!=-1;j=heavy[j])
                    rt[j] = i, pos[j] = tpos++;
        }
    }
    int dfs(int x,int p){
        par[x] = p;
        int sz=1,mx=0,sb;
        for(int y:g[x]) if(y != p){
            depth[y] = depth[x]+1;
            sz += sb = dfs(y,x);
            if(sb>mx) mx=sb, heavy[x]=y;
        }
        return sz;
    }
    T query(int u, int v){
        T resu=low, resv=low;
        for(;rt[u]!=rt[v]; v=par[rt[v]]){
            if(depth[rt[u]] > depth[rt[v]]) swap(u,v), swap(resu,resv);
            resv = OP(tr.query(pos[rt[v]],pos[v]+1),resv);
        }
        if(depth[u] > depth[v]) swap(u,v), swap(resu,resv);
        resv = OP(tr.query(pos[u]+1,pos[v]+1),resv);
        swap(resv.pre,resv.suf); //specific reversing action
        return OP(resv,resu);
    }
    void modify(int u, int v, T x){
        if(par[u] != v) swap(u,v);
        tr.modify(pos[u],x);
    }
};

struct data{
    int pre,suf;
    int sum;
    int all1;
}empt{0,0,0,1},one{1,1,0,1},zero{0,0,0,0};

int f[maxn];
data comb(data a,data b){
    if(a.pre==empt.pre && a.suf==empt.suf && a.all1==empt.all1) return b;
    if(b.pre==empt.pre && b.suf==empt.suf && b.all1==empt.all1) return a;
    if(a.all1 && b.all1){
        int t=a.pre+b.pre;
        return data{t,t,0,1};
    }
    if(a.all1) return data{a.pre+b.pre,b.suf,b.sum,0};
    if(b.all1) return data{a.pre,a.suf+b.pre,a.sum,0};
    return data{a.pre,b.suf,b.sum+a.sum+f[a.suf+b.pre],0};
}

typedef tuple<int,int,int> edge;
typedef tuple<int,int,int,int> query;

vi g[maxn];
query que[maxn];
edge e[maxn];
int ans[maxn];

int main(){
    int n,q,a,b,l,w,id;
    scanf("%d%d",&n,&q);
    rep(i,1,n)cin>>f[i];
    rep(i,0,n-1){
        scanf("%d%d%d",&a,&b,&w);
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
        e[i] = edge(w,a,b);
    }
    HLD<data,comb,empt> tr(n,g,one);
    rep(i,0,q){
        scanf("%d%d%d",&a,&b,&l);
        --a,--b;
        que[i]=query(l,a,b,i);
    }
    sort(que,que+q);
    sort(e,e+n-1);
    int j=0,u,v;
    rep(i,0,q){
        tie(l,a,b,id) = que[i];
        while(j+1<n && l > get<0>(e[j])) {
            tie(w,u,v) = e[j++];
            tr.modify(u,v,zero);
        }
        data d = tr.query(a,b);
        ans[id] = comb(comb(zero,d),zero).sum;
    }
    rep(i,0,q)printf("%d\n",ans[i]);
    return 0;
}