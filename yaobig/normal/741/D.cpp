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
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}

void debug_out() {cerr << endl;} 
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 500000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int msk[maxn+5],dep[maxn+5];
int ans[maxn+5];
int cnt[1<<22];
// indices start from 1.
struct dsu_on_tree
{
    vi e[maxn+5];
    int sz[maxn+5],dfn,tin[maxn+5],tout[maxn+5],ver[maxn+5];
    void init(int _n) {rep(i,1,_n) e[i].clear();}
    void addedge(int x,int y) 
    {
        e[x].pb(y);
        e[y].pb(x);
    }
    void calsz(int now,int fa)
    {
        sz[now]=1;
        for(auto v: e[now]) if(v!=fa) calsz(v,now),sz[now]+=sz[v];
    }
    void dfs(int now,int fa,bool keep)
    {
        tin[now]=++dfn; ver[dfn]=now;
        int mx=0,hv=-1;
        for(auto v: e[now]) if(v!=fa && chmax(mx,sz[v])) hv=v;
        for(auto v: e[now]) if(v!=fa && v!=hv) dfs(v,now,0);
        if(hv!=-1) dfs(hv,now,1);
        for(auto v: e[now]) if(v!=fa) chmax(ans[now],ans[v]);
        auto check=[&](int v) {
            int MSK=msk[v];
            if(cnt[MSK]>0) chmax(ans[now],cnt[MSK]+dep[v]-2*dep[now]);
            rep(d,0,22-1) if(cnt[MSK ^ (1<<d)]>0) chmax(ans[now],cnt[MSK ^ (1<<d)]+dep[v]-2*dep[now]);
        };
        check(now);
        chmax(cnt[msk[now]],dep[now]);
        for(auto v: e[now]) if(v!=fa && v!=hv)
        {
            rep(x,tin[v],tout[v]) check(ver[x]);
            rep(x,tin[v],tout[v]) chmax(cnt[msk[ver[x]]],dep[ver[x]]);
        }
        tout[now]=dfn;
        if(keep==0) rep(x,tin[now],tout[now]) cnt[msk[ver[x]]]=0;
    }
    void work(int rt)
    {
        calsz(rt,0);
        dfs(rt,0,1);
    }
}dsu;



int main()
{
    int n; scanf("%d",&n);
    dsu.init(n);

    dep[1]=1;
    rep(i,2,n)
    {
        int f; char s[4]; scanf("%d%s",&f,s);
        dsu.addedge(i,f);
        msk[i] = msk[f] ^ (1<<((int)s[0]-'a'));
        dep[i] = dep[f]+1;
    }
    dsu.work(1);
    rep(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}