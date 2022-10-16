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

const int maxn = 400;
const int inf = 0x3f3f3f3f;
const int mod = 1'000'000'007;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

int main()
{
    int n,m,x; scanf("%d%d%d",&n,&m,&x);
    if(n>m) return puts("0"), 0;
    static int dp[2][maxn+5][maxn+5];
    int cur = 0;
    dp[cur][0][0] = 1;
    rep(i,1,m)
    {
        int old = cur; cur ^= 1;
        rep(cnt,0,n) rep(open,0,cnt) dp[cur][cnt][open] = 0;
        rep(cnt,0,n) rep(open,0,cnt) if(dp[old][cnt][open])
        {
            int val = dp[old][cnt][open];
            if(i!=x) chadd(dp[cur][cnt][open], val);
            if(i!=x && open>=1) chadd(dp[cur][cnt][open-1], val);
            if(cnt<n) chadd(dp[cur][cnt+1][open+1], val);
            if(cnt<n) chadd(dp[cur][cnt+1][open], val);
        }
    }
    int ans = dp[cur][n][0];
    rep(i,1,n) ans = 1ll*ans*i%mod;
    printf("%d\n",ans);
    return 0;
}