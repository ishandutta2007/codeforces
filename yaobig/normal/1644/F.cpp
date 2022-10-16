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

const int maxn = 200'000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,int y) {x-=y; if(x<0) x+=mod;}

ll qp(ll a,ll k)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%mod) if(k&1) res=res*a%mod;
    return res;
}

int fac[maxn+5],ifac[maxn+5],inv[maxn+5];

int main()
{
    // pre-calculattion for binomial coefficient.
    inv[1] = fac[0] = ifac[0] = 1;
    rep(i,2,maxn) inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i] = 1ll*fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i] = 1ll*ifac[i-1]*inv[i]%mod;

    static int S[maxn+5];
    memset(S,-1,sizeof S);
    static int ps[maxn+5];
    ps[0] = 1;
    rep(i,1,maxn) 
    {
        ps[i] = ps[i-1];
        if(i&1) chsub(ps[i],ifac[i]);
        else chadd(ps[i],ifac[i]);
    }

    int n,k; scanf("%d%d",&n,&k);
    if(n==1 || k==1) return puts("1"),0;
    auto solve = [&](int n) {
        if(S[n]!=-1) return S[n];
        int res = 0;
        int U = min(k,n);
        rep(i,0,U)
        {
            int tmp = 1ll*qp(i,n)*ifac[i]%mod;
            chadd(res,1ll*tmp*ps[U-i]%mod);
        }
        chsub(res,1);
        return S[n] = res;
    };

    static int maxp[maxn+5];
    rep(i,2,maxn) if(maxp[i]==0) for(int j=i;j<=maxn;j+=i) maxp[j] = i;
    
    static int mu[maxn+5];
    mu[1] = 1;
    rep(i,2,maxn)
    {
        int p = maxp[i];
        mu[i] = maxp[i/p]==p ? 0 : -mu[i/p];
    }
    int ans = 0;
    rep(i,1,n) if(mu[i])
    {
        if(mu[i]==1) chadd(ans,solve((n+i-1)/i));
        else chsub(ans,solve((n+i-1)/i));
    }
    printf("%d\n",ans);
    return 0;
}