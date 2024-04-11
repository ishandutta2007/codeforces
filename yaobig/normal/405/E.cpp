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

vector<pii> e[maxn+5];
bool mark[maxn+5],vis[maxn+5];

void dfs(int now,int fa)
{
    vis[now] = 1;
    for(auto [v,id]: e[now]) if(vis[v]==0) dfs(v,now);
    vi A;
    int fid = -1;
    for(auto [v,id]: e[now]) if(mark[id]==0)
    {
        if(v==fa) fid = id;
        else A.pb(v), mark[id] = 1;
    }
    if(sz(A)&1) A.pb(fa), mark[fid] = 1;
    for(int i=0;i<sz(A);i+=2) printf("%d %d %d\n",A[i],now,A[i+1]);
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb({y,i});
        e[y].pb({x,i});
    }
    if(m&1) puts("No solution");
    else dfs(1,0);
    
    return 0;
}