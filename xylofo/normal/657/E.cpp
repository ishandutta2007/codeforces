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

template<class T>
struct rmq{
    static const int lgn = 20;
    vector<T> jmp[lgn];
    rmq(vector<T>& w){
        int n=w.size();
        rep(i,0,lgn) jmp[i].resize(n);
        jmp[0]=w;
        rep(k,0,lgn-1) rep(i,0,n)
            jmp[k+1][i] = min(jmp[k][i],jmp[k][min(n-1,i+(1<<k))]);
    }
    T query(int a,int b){
        assert(b>a);
        int d = 31 - __builtin_clz(b-a);
        return min(jmp[d][a],jmp[d][b-(1<<d)]);
    }
};

const int maxn = 300005;
const int maxlg = 1;

struct Tree{
    int n,rt,T=0;
    int par[maxlg][maxn], depth[maxn], enter[maxn], exit[maxn];
    rmq<pii>* r;
    vector<pii> rr;
    Tree(vvi& g,int root=0):n(g.size()),rt(root){ dfs(rt, rt, g); r=new rmq<pii>(rr);}
    void dfs(int x, int p, vvi& g){
        depth[x] = (p==x) ? 0 : (depth[p]+1);
        par[0][x] = p;
        if(p!=x)rr.pb({depth[p],p});
        enter[x]=T++;
        for(int y:g[x]) if(y!=p) dfs(y,x,g);
        exit[x]=T;
    }
    int lca(int a, int b){
        if(a==b)return a;
        a=enter[a],b=enter[b];
        return r->query(min(a,b),max(a,b)).Y;
    }
};
vi gg[maxn];
void compact(vi& sub,Tree &t){
    static auto cmp = [&](int a,int b){return t.enter[a]<t.enter[b];};
    sort(allof(sub),cmp);
    int k=sub.size()-1;
    rep(i,0,k) sub.pb(t.lca(sub[i],sub[i+1]));
    sort(allof(sub),cmp);
    sub.erase(unique(allof(sub)),sub.end());
    stack<int> st;
    for(int x:sub){
        while(!st.empty() && t.exit[st.top()] <= t.enter[x]) st.pop();
        if(!st.empty()) gg[st.top()].pb(x), gg[x].pb(st.top());
        st.push(x);
    }
}

namespace bcc2{
    int bcc[maxn],tmm[maxn],low[maxn];
    int T=1,comp=0;
    stack<int> st;
    void dfs(int x,int p){
        tmm[x] = low[x] = T++;
        st.push(x);
        int onep=0;
        for(int y:gg[x]) if(y!=0){ if(y!=p || onep){
            if(tmm[y]) low[x] = min(low[x],tmm[y]);
            else dfs(y,x), low[x] = min(low[x],low[y]);
        }else onep++;
        }
        if(low[x]==tmm[x]){
            bcc[x] = ++comp;
            while(st.top()!=x)
                bcc[st.top()] = comp, st.pop();
            st.pop();
        }
    }
}

vvi g;
int bcc[maxn],tmm[maxn],low[maxn];
int T=1,comp=0;
stack<int> st;
void dfs(int x,int p){
    tmm[x] = low[x] = T++;
    st.push(x);
    int onep=0;
    for(int y:g[x]) if(y!=p || onep){
        if(tmm[y]) low[x] = min(low[x],tmm[y]);
        else dfs(y,x), low[x] = min(low[x],low[y]);
    }else onep++;
    if(low[x]==tmm[x]){
        bcc[x] = ++comp;
        while(st.top()!=x) 
            bcc[st.top()] = comp, st.pop();
        st.pop();
    }
}
int n,m,q,a,b,x[maxn],y[maxn];
int R=0;
int rot(int element) { element=(element+R)%n; if (element==0) { element=n; } return element; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>q;
    g.resize(n+5);
    rep(i,0,m){
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
        x[i]=a, y[i]=b;
    }
    rep(i,1,n+1) if(!tmm[i]) dfs(i,-1), g[0].pb(bcc[i]);
    g.resize(1);
    g.resize(comp+1,vi());
    rep(i,0,m) {
        a=bcc[x[i]], b=bcc[y[i]];
        if(a==b) continue;
        g[a].pb(b);
        g[b].pb(a);
    }
    Tree tree(g,0);
    //rep(i,0,n+1) cout<<i<<" = "<<bcc[i]<<endl;
    //rep(i,0,g.size()) rep(j,0,g[i].size())if(i<g[i][j]) cout<<i<<" "<<g[i][j]<<endl;
    rep(_i,0,q){
        int n,m,t;
        cin>>n>>m;
        vi v(n);
        rep(i,0,n){
            cin>>t;
            v[i]=bcc[rot(t)];
        }
        vi w=v;
        rep(i,0,m){
            cin>>a>>b;
            a=bcc[rot(a)], b=bcc[rot(b)];
            w.pb(a),w.pb(b);
            if(a!=b){
                gg[a].pb(b);
                gg[b].pb(a);
            }
        }
        sort(allof(w));
        w.erase(unique(allof(w)),w.end());
        compact(w,tree);
        bcc2::dfs(v[0],-1);
        //rep(i,0,n) rep(j,0,gg[i].size())if(i<gg[i][j]) cout<<i<<" "<<gg[i][j]<<endl;
        //cout<<endl;
        int s=bcc2::bcc[v[0]];
        for(int i:v) if(bcc2::bcc[i]!=s) {cout<<"NO"<<endl; goto fail;}
        cout<<"YES"<<endl;
        R=(R+_i+1)%(::n);
        fail:
        for(int i:w){
            gg[i].clear();
            bcc2::bcc[i]=0;
            bcc2::tmm[i]=0;
            bcc2::low[i]=0;
        }
    }
    return 0;
}