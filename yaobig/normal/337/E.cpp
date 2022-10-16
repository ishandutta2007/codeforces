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

const int maxn = 10;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

ll a[maxn+5];
vector<ll> pfac[maxn+5];
int dp[2][1<<8];

int main()
{
    int n; scanf("%d",&n);
    rep(i,0,n-1) scanf("%lld",&a[i]);
    sort(a,a+n);
    rep(i,0,n-1)
    {
        ll x = a[i];
        for(int j = 2; 1ll*j*j<=x; j++) if(x%j==0)
        {
            pfac[i].pb(j);
            while(x%j==0) x /= j;
        }
        if(x>1) pfac[i].pb(x);
    }
    int cur = 1;
    rep(i,0,n-1)
    {
        int N = 1<<i;
        int old = cur; cur ^= 1;
        rep(msk,0,N*2-1) dp[cur][msk] = inf;
        rep(S,0,N-1) if(dp[old][S]!=inf)
        {
            auto cal = [&](int T) {
                ll x = a[i];
                rep(j,0,i-1) if(T>>j&1) 
                {
                    if(x%a[j]!=0) return inf;
                    x /= a[j];
                }
                int cnt = 1;
                for(auto p: pfac[i]) while(x%p==0) cnt++, x/=p;
                return cnt;
            };
            if(a[i]==pfac[i][0]) chmin(dp[cur][S^(1<<i)],dp[old][S]+1);
            else chmin(dp[cur][S^(1<<i)],dp[old][S]+cal(0));
            for(int T = S; T; T = (T-1)&S) chmin(dp[cur][S^T^(1<<i)],dp[old][S]+cal(T));
        }
    }
    int ans = inf;
    rep(S,0,(1<<n)-1) chmin(ans,dp[cur][S] + (__builtin_popcount(S)!=1));
    printf("%d\n",ans);
    return 0;
}