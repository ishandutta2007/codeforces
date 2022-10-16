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

const int maxn = 300000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,const int &y) {x+=y; if(x>=mod) x-=mod;}

vi e[maxn+5];
int dp[maxn+5][3]; // 0: match upwards; 1: match downwards; 2: not matched.

void dfs(int now,int fa)
{
    dp[now][0] = dp[now][2] = 1;
    int tmp[2] = {1,0};
    for(auto v: e[now]) if(v!=fa)
    {
        dfs(v,now);
        int c = (2ll*dp[v][1]+dp[v][2])%mod;
        dp[now][0] = 1ll*dp[now][0]*c%mod;
        tmp[1] = (1ll*tmp[1]*c + 1ll*tmp[0]*dp[v][0])%mod;
        tmp[0] = 1ll*tmp[0]*c%mod;
        dp[now][2] = 1ll*dp[now][2]*(dp[v][1]+dp[v][2])%mod;
    }
    dp[now][1] = tmp[1];
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1,0);
    printf("%d\n",(dp[1][1]+dp[1][2])%mod);
    return 0;
}