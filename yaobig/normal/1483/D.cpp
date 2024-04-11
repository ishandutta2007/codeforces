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
string to_string(bool b) {return (b ? "true" : "false");}
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

const int maxn = 600;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

struct node {int u,v,w;};

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    vector<node> e(m);
    for(auto &[u,v,w]: e) scanf("%d%d%d",&u,&v,&w);
    static ll dis[maxn+5][maxn+5];
    rep(i,1,n) rep(j,1,n) dis[i][j] = i==j ? 0 : 1ll<<60;
    for(auto [u,v,w]: e) chmin(dis[u][v], (ll)w), chmin(dis[v][u], (ll)w);
    rep(k,1,n) rep(i,1,n) rep(j,1,n) chmin(dis[i][j], dis[k][i]+dis[k][j]);
    static ll f[maxn+5][maxn+5]; 
    rep(u,1,n) rep(b,1,n) f[u][b] = -1ll<<60;
    int q; scanf("%d",&q);
    while(q--)
    {
        int u,v,l; scanf("%d%d%d",&u,&v,&l);
        rep(b,1,n) chmax(f[u][b], l-dis[v][b]);
        rep(b,1,n) chmax(f[v][b], l-dis[u][b]);
    }
    int ans = 0;
    for(auto [a,b,w]: e)
    {
        int ok = 0;
        rep(u,1,n) if(dis[u][a]+w<=f[u][b]) { ok = 1; break; }
        ans += ok;
    }
    printf("%d\n",ans);
    return 0;
}