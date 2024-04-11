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
template <typename A> string to_string(A v) 
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
//using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 600000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

struct Euler_tour_recursive
{
    int n,tot;
    vector<pii> e[maxn+5];
    void init(int _n)
    {
        n=_n; tot=0;
        rep(i,0,n) e[i].clear();
    }
    void addedge(int x,int y)
    {
        e[x].pb({y,++tot}); e[y].pb({x,-tot});
    }
    vi work()
    {
        vi path;
        vi cur(n+1),vis(tot+1);
        function<void(int)> dfs = [&](int now) {
            static vi cur(n+1), vis(tot+1);
            for(int &i=cur[now];i<sz(e[now]);)
            {
                auto [v,id]=e[now][i]; i++;
                if(vis[abs(id)]) continue;
                vis[abs(id)]=1;
                dfs(v);
                path.pb(id);
            }
        };
        rep(i,0,n) dfs(i);
        return path;
    }
}eu;

int ans[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    eu.init(n*2);
    rep(i,1,m)
    {
        int u,v,w; scanf("%d%d%d",&u,&v,&w); 
        if(w==2) u+=n, v+=n;
        eu.addedge(u,v);
    }
    int cnt = 0;
    rep(i,1,n)
    {
        if(sz(eu.e[i])&1 && sz(eu.e[i+n])&1) eu.addedge(i,i+n), cnt++;
        else if(sz(eu.e[i])&1) eu.addedge(0,i), cnt++;
        else if(sz(eu.e[i+n])&1) eu.addedge(0,i+n);
    }
    auto path = eu.work();
    for(auto id: path) if(abs(id)<=m) ans[abs(id)] = id>0?1:2;
    printf("%d\n",cnt);
    rep(i,1,m) printf("%d",ans[i]);
    puts("");
    return 0;
}