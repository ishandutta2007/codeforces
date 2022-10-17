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
int imp[maxn];
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
        if(!st.empty()) gg[st.top()].pb(x);
        st.push(x);
    }
}
pii dfs(int x,int p){
    pii cnt(0,0);
    for(int y:gg[x]) if(y!=p){
        pii p = dfs(y,x);
        cnt.X+=p.X, cnt.Y+=p.Y;
        //cout<<y<<": "<<p.X<<" "<<p.Y<<endl;
    }
    //cout<<x<<"::"<<cnt.X<<" "<<cnt.Y<<endl;
    if(imp[x]) return mp(1,cnt.X+cnt.Y);
    if(cnt.X<2) return cnt;
    return mp(0,cnt.Y+1);
    
}
int solve(vi& sub,Tree &t){
    int ans=1e9;
    for(int i:sub) imp[i]=true;
    for(int i:sub) if(i!=t.rt && imp[t.par[0][i]]) ans=-1;
    compact(sub,t);
    ans = min(ans,dfs(sub[0],sub[0]).Y);
    for(int i:sub) imp[i]=false, gg[i].clear();
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n;
    vvi g(n+1);
    rep(i,1,n){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    Tree t(g,1);
    cin>>m;
    rep(i,0,m){
        cin>>n;
        vi v(n);
        rep(i,0,n)cin>>v[i];
        cout<<solve(v,t)<<endl;
    }
    return 0;
}