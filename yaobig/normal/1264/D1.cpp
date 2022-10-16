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

const int maxn = 2000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,int y) {x-=y; if(x<0) x+=mod;}

char s[maxn+5];
int dp[maxn+5][maxn+5];

int main()
{
    scanf("%s",s+1);
    int n = strlen(s+1);
    int inv2 = (mod+1)/2, inv4 = 1ll*inv2*inv2%mod;
    rep(len,2,n) rep(l,1,n-len+1)
    {
        int r = l+len-1;
        if(s[l]==')') dp[l][r] = dp[l+1][r];
        else if(s[r]=='(') dp[l][r] = dp[l][r-1];
        else if(s[l]=='(' && s[r]==')') dp[l][r] = (dp[l+1][r-1]+1)%mod;
        else if(s[l]=='(' && s[r]=='?') dp[l][r] = 1ll*(dp[l+1][r-1]+1 + dp[l][r-1])*inv2%mod;
        else if(s[l]=='?' && s[r]==')') dp[l][r] = 1ll*(dp[l+1][r-1]+1 + dp[l+1][r])*inv2%mod;
        else if(s[l]=='?' && s[r]=='?') 
        {
            dp[l][r] = inv4;
            chadd(dp[l][r], 1ll*dp[l][r-1]*inv2%mod);
            chadd(dp[l][r], 1ll*dp[l+1][r]*inv2%mod);
        }
        else assert(0);
    }
    int ans = dp[1][n];
    rep(i,1,n) if(s[i]=='?') ans = 2ll*ans%mod;
    printf("%d\n",ans);
    return 0;
}