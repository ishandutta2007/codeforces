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

const int maxn = 500'000;
const int inf = 0x3f3f3f3f;
// const int mod = 998244353;

int a[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    auto solve = [&]() {
        vi f(n+2,0), g(n+2,0);
        rep(i,1,n)
        {
            f[i] = inf;
            if(a[i]>a[i-1]) chmin(f[i], f[i-1]);
            if(a[i]>f[i-1]) chmin(f[i], a[i-1]);
        }
        per(i,1,n)
        {
            g[i] = inf;
            if(a[i]>a[i+1]) chmin(g[i], g[i+1]);
            if(a[i]>g[i+1]) chmin(g[i], a[i+1]);
        }

        int piv = max_element(a+1,a+n+1) - a;
        static int dp[maxn+5][2];
        dp[piv][0] = f[piv];
        dp[piv][1] = 0;
        rep(i,piv+1,n)
        {
            dp[i][0] = inf; dp[i][1] = 0;
            if(a[i]<a[i-1]) chmin(dp[i][0], dp[i-1][0]);
            if(a[i]<dp[i-1][1]) chmin(dp[i][0], a[i-1]);
            if(a[i]>a[i-1]) chmax(dp[i][1], dp[i-1][1]);
            if(a[i]>dp[i-1][0]) chmax(dp[i][1], a[i-1]);
        }
        int res = 0;
        rep(i,piv+1,n) if(g[i]<dp[i][1]) res++;
        return res;
    };
    int ans = 0;
    ans += solve();
    reverse(a+1,a+n+1);
    ans += solve();
    printf("%d\n",ans);
    return 0;
}