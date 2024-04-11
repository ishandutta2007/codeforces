#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
#define lc (v+1)
#define rc (v+2*(mid-l+1))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e5+1, MN=3e5, L=19;

int n;
vector<int> a[MAXN];
struct SegmentTree{
    int a[2*MAXN], lz[2*MAXN];
    void push(int v, int l, int r){
        a[v]+=lz[v];
        if (l!=r) lz[lc]+=lz[v], lz[rc]+=lz[v];
        lz[v]=0;
    }
    void upd(int ql, int qr, int val, int v=1, int l=1, int r=MN){
        push(v,l,r);
        if (l>qr||r<ql) return;
        if (l>=ql&&r<=qr){ lz[v]+=val, push(v,l,r); return; }
        upd(ql,qr,val,lc,l,mid), upd(ql,qr,val,rc,mid+1,r);
        a[v]=a[lc]+a[rc];
    }
    int qry(int ql, int qr,int v=1, int l=1, int r=MN){
        push(v,l,r);
        if (l>qr||r<ql) return 0;
        if (l>=ql&&r<=qr) return a[v];
        return qry(ql,qr,lc,l,mid)+qry(ql,qr,rc,mid+1,r);
    }
    void reset(){
        for (int i=1;i<=2*n;++i) a[i]=lz[i]=0;
    }
};

namespace Graph{
    SegmentTree st, act;
    vector<int> adj[MAXN];
    int par[MAXN], son[MAXN], sz[MAXN], head[MAXN], dep[MAXN], in[MAXN], out[MAXN], T, block[MAXN];
    int up[MAXN][L+1];
    int curr;
    void dfs0(int v){
        sz[v]=1;
        up[v][0]=par[v];
        for (int i=1;i<=L;++i) up[v][i]=up[up[v][i-1]][i-1];
        for (int to:adj[v]){
            if (to==par[v]) continue;
            par[to]=v; dep[to]=dep[v]+1;
            dfs0(to); sz[v]+=sz[to];
            if (sz[to]>sz[son[v]]) son[v]=to;
        }
    }

    void dfs1(int v, int h){
        in[v]=++T;
        head[v]=h;
        if (son[v]) dfs1(son[v],h);
        for (int to:adj[v]){
            if (to==par[v]||to==son[v]) continue;
            dfs1(to,to);
        }
        out[v]=T;
    }
    bool isanc(int a, int b){ return in[a]<=in[b]&&out[a]>=out[b]; }
    void upd(int v, int x){
        while (v) st.upd(in[head[v]],in[v],x), v=par[head[v]];
    }
    int qry(int v){ return st.qry(in[v],in[v]); }
    bool empty(int v, int p){
        while (head[v]!=head[p]){
            if (act.qry(in[head[v]],in[v])) return 0;
            v=par[head[v]];
        }
        if (act.qry(in[p],in[v])) return 0;
        else return 1;
    }
    int first_anc(int v);
    void activate(int v){
        if (qry(v)==0){
            int p=first_anc(v);
            block[v]=p;
            if (p==-1) curr++;
            else{
                act.upd(in[p],in[p],-1);
            }
            act.upd(in[v],in[v],1);
        }
    }
    void deactivate(int v){
        if (qry(v)==0){
            int p=block[v];
            if (p==-1) curr--;
            else{
                act.upd(in[p],in[p],1);
            }
            act.upd(in[v],in[v],-1);
        }
    }
    int first_anc(int v){
        if (act.qry(in[v],in[v])==1) return v;
        for (int i=L;i>=0;--i){
            if (empty(v,up[v][i])) v=up[v][i];
        }
        if (v==1) return -1;
        else return par[v];
    }
    void reset(){
        st.reset();
        act.reset();
        for (int i=1;i<=n;++i) adj[i].clear();
        for (int i=1;i<=n;++i){
            par[i]=son[i]=sz[i]=head[i]=dep[i]=in[i]=out[i]=block[i]=0;
            ms(up[i],0);
        }
    }
    void init(){
        reset();
        for (int i=2;i<=n;++i){
            int p; cin >> p;
            adj[p].push_back(i);
        }
        par[1]=1;
        T=0;
        curr=0;
        dfs0(1);
        dfs1(1,1);
    }
}

void solve(int v, int p, int &ans){
    Graph::activate(v);
    ans=max(ans,Graph::curr);
    for (int to:a[v]){
        if (to==p) continue;
        solve(to,v,ans);
    }
    Graph::deactivate(v);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n;
        for (int i=1;i<=n;++i) a[i].clear();
        for (int i=2;i<=n;++i){
            int p; cin >> p;
            a[p].push_back(i);
        }
        Graph::init();
        int ans=1;
        solve(1,1,ans);
        cout << ans << '\n';
    }
}

/*
1
7
1 1 3 4 4 5
1 2 1 4 2 5
*/