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

int a[maxn+5][4];
ll dp[maxn+5][4];

int main()
{
    int n; scanf("%d",&n);
    rep(j,1,3) rep(i,1,n) scanf("%d",&a[i][j]);
    dp[1][2] = dp[1][3] = -1ll<<60;
    ll sum = 0, mx_top = 0, mx_bottom = -1ll<<60;
    rep(i,2,n+1)
    {
        rep(j,1,3) sum += a[i-1][j];
        rep(j,1,3) dp[i][j] = -1ll<<60;
        rep(j,1,3) chmax(dp[i][j], dp[i-1][j]+a[i-1][j]);
        chmax(dp[i][1], dp[i-1][2]+a[i-1][2]+a[i-1][1]);
        chmax(dp[i][3], dp[i-1][2]+a[i-1][2]+a[i-1][3]);
        chmax(dp[i][2], dp[i-1][1]+a[i-1][1]+a[i-1][2]);
        chmax(dp[i][2], dp[i-1][3]+a[i-1][3]+a[i-1][2]);
        chmax(dp[i][1], mx_bottom+sum);
        chmax(dp[i][3], mx_top+sum);
        chmax(mx_top, dp[i][1]-sum);
        chmax(mx_bottom, dp[i][3]-sum);
    }
    printf("%lld\n",dp[n+1][3]);
    return 0;
}