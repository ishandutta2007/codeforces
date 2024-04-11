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

const int maxn = 300;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

const int maxA = 40000;

int fac[maxn+5],ifac[maxn+5],inv[maxn+5];
int binom(int n,int m)
{
    if(m<0 || n<m) return 0;
    return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}


int main()
{
    inv[1] = fac[0] = ifac[0] = 1;
    rep(i,2,maxn) inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i] = 1ll*fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i] = 1ll*ifac[i-1]*inv[i]%mod;

    static int np[maxA+5]; vi p2{};
    rep(i,2,maxA) if(np[i]==0) 
    {
        p2.pb(i*i);
        for(int j=i;j<=maxA;j+=i) np[j] = 1;
    }

    int n; scanf("%d",&n);
    map<int,int> cnt;
    rep(i,1,n)
    {
        int x; scanf("%d",&x);
        for(auto y: p2) while(x%y==0) x /= y;
        cnt[x]++;
    }
    vi a; for(auto [_,c]: cnt) a.pb(c);

    static int dp[2][maxn+5];
    int N = 0; // number of elements added.
    int cur = 0; dp[cur][0] = 1;
    for(auto c: a)
    {
        int old = cur; cur ^= 1;
        memset(dp[cur],0,sizeof dp[cur]);
        rep(bad,0,N) if(dp[old][bad]) rep(x,0,c-1) rep(y,0,bad)
        {
            int z = c - x - y;
            if(z>=0) chadd(dp[cur][bad+x-y], 1ll * dp[old][bad] * fac[c] % mod * binom(c-1,x) % mod * binom(N+1-bad,z) % mod * binom(bad,y) % mod);
        }
        N += c;
    }
    printf("%d\n",dp[cur][0]);
    return 0;
}