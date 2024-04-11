#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
template<typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template<typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {cerr << endl;} 
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int c[maxn+5];
vector<pii> qpool[maxn+5];
int ans[maxn+5];
int cnt[maxn+5],sum[maxn+5];
// indices start from 1.
struct dsu_on_tree
{
    vi e[maxn+5];
    int sz[maxn+5],dfn,tin[maxn+5],tout[maxn+5],id[maxn+5];
    void init(int _n) {rep(i,1,_n) e[i].clear();}
    void addedge(int x,int y) 
    {
        e[x].pb(y); e[y].pb(x);
    }
    void calsz(int now,int fa)
    {
        sz[now]=1;
        for(auto v: e[now]) if(v!=fa) calsz(v,now),sz[now]+=sz[v];
    }
    void dfs(int now,int fa,bool keep)
    {
        tin[now]=++dfn; id[dfn]=now;
        int mx=0,hv=-1;
        for(auto v: e[now]) if(v!=fa && chmax(mx,sz[v])) hv=v;
        for(auto v: e[now]) if(v!=fa && v!=hv) dfs(v,now,0);
        if(hv!=-1) dfs(hv,now,1);

        sum[++cnt[c[now]]]++;

        for(auto v: e[now]) if(v!=fa && v!=hv)
        {
            rep(i,tin[v],tout[v]) sum[++cnt[c[id[i]]]]++;
        }
        for(auto [k,i]: qpool[now]) ans[i] = sum[k];
        tout[now]=dfn;
        if(keep==0) rep(i,tin[now],tout[now]) sum[cnt[c[id[i]]]--]--;
    }
    void work(int rt)
    {
        calsz(rt,0);
        dfs(rt,0,1);
    }
}dsu;

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    rep(i,1,n) scanf("%d",&c[i]);
    dsu.init(n);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        dsu.addedge(x,y);
    }
    rep(i,1,q)
    {
        int v,k; scanf("%d%d",&v,&k);
        qpool[v].pb({k,i});
    }
    dsu.work(1);
    rep(i,1,q) printf("%d\n",ans[i]);
    return 0;
}