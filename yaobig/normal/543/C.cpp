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

const int maxn = 20;
const int inf = 0x3f3f3f3f;
//const int mod = 998244353;

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    static char s[maxn+5][maxn+5];
    static int a[maxn+5][maxn+5];
    rep(i,0,n-1) scanf("%s",s[i]);
    rep(i,0,n-1) rep(j,0,m-1) scanf("%d",&a[i][j]);
    
    static pii g[maxn+5][maxn+5];
    rep(c,0,m-1) rep(ch,0,25)
    {
        int sum = 0, mx = 0, msk = 0;
        rep(r,0,n-1) if(s[r][c]=='a'+ch) sum += a[r][c], chmax(mx,a[r][c]), msk |= 1<<r;
        rep(r,0,n-1) if(s[r][c]=='a'+ch) g[r][c] = pii{msk,sum-mx};
    }
    int N = 1<<n;
    vi dp(N,inf); dp[0] = 0;
    rep(msk,0,N-1) if(msk!=N-1)
    {
        int low = __builtin_ctz(msk^(N-1));
        rep(c,0,m-1) chmin(dp[msk^(1<<low)], dp[msk]+a[low][c]);
        rep(c,0,m-1)
        {
            auto [M,w] = g[low][c];
            chmin(dp[msk|M], dp[msk]+w);
        }
    }
    printf("%d\n",dp[N-1]);
    return 0;
}