#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> inline bool chmax(T &a, T b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) {if(b<a) {a=b; return 1;} return 0;}
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

const int maxn = 200'000;
const int inf = 0x3f3f3f3f;
const int mod = 1073741824;

int w[maxn+5];
vector<pii> e[maxn+5];

struct Centroid_Decomposition
{
    array<int,maxn+5> sz;
    array<bool,maxn+5> vis;
    int best; db ans;
    void solve(int _,int SZ)
    {
        int mn = inf, rt = -1;
        function<void(int,int)> getrt = [&](int now,int fa) {
            sz[now]=1;
            int mx = 0;
            for(auto [v,_]: e[now]) if(v!=fa && vis[v]==0)
            {
                getrt(v,now);
                sz[now]+=sz[v];
                chmax(mx,sz[v]);
            }
            chmax(mx,SZ-sz[now]);
            if(chmin(mn,mx)) rt=now;
        };
        getrt(_,0); vis[rt]=1; 

        static db der[maxn+5];
        db val = 0;
        function<void(int,int,int,int)> dfs = [&](int now,int fa,int from,int dis) {
            der[from] += sqrt(dis) * w[now];
            val += dis * sqrt(dis) * w[now];
            for(auto [v,w]: e[now]) if(v!=fa) dfs(v,now,from,dis+w);
        };
        db sum = 0;
        for(auto [v,w]: e[rt]) der[v] = 0, dfs(v,rt,v,w), sum += der[v];
        if(chmin(ans, val)) best = rt;

        for(auto [v,_]: e[rt]) if(vis[v]==0 && der[v]>sum-der[v]+1e-10) solve(v, sz[v]<sz[rt] ? sz[v] : SZ-sz[rt]);
    }
    void build(int n)
    {
        rep(i,1,n) vis[i] = 0;
        ans = 1e100; best = -1;
        solve(1,n);
    }
}cd;

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&w[i]);
    rep(i,1,n-1)
    {
        int x,y,w; scanf("%d%d%d",&x,&y,&w);
        e[x].pb({y,w});
        e[y].pb({x,w});
    }
    cd.build(n);
    printf("%d %.9f\n",cd.best,cd.ans);
    return 0;
}