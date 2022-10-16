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

const int maxn = 1000000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,const int &y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,const int &y) {x-=y; if(x<0) x+=mod;}

ll qp(ll a,ll k)
{
    ll res=1;
    for(;k;k>>=1,a=a*a%mod) if(k&1) res=res*a%mod;
    return res;
}

int cnt[maxn+5];
int fac[maxn+5],ifac[maxn+5],inv[maxn+5],phi[maxn+5];

int main()
{
    inv[1] = fac[0] = ifac[0] = 1;
    rep(i,2,maxn) inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i] = 1ll*fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i] = 1ll*ifac[i-1]*inv[i]%mod;
    rep(i,1,maxn) phi[i] = i;
    rep(i,1,maxn) for(int j=i*2;j<=maxn;j+=i) phi[j] -= phi[i];

    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        rep(i,1,n) cnt[i] = 0;
        rep(i,1,n)
        {
            int x; scanf("%d",&x); cnt[x]++;
        }
    
        vi A;
        rep(i,1,n) if(cnt[i]) A.pb(cnt[i]);
        if(sz(A)==1) {puts("1"); continue;}

        int g = 0;
        for(auto &x: A) g = __gcd(x,g);
        
        auto solve = [&](int d)
        {
            int C = 1;
            C = 1ll*C*fac[n/d]%mod;
            for(auto x: A) C = 1ll*C*ifac[x/d]%mod;
            int S = 1ll*n*C%mod;
            for(auto x: A) if(x/d>=2)
            {
                int tmp = C;
                tmp = 1ll*tmp*ifac[n/d]%mod*fac[n/d-2]%mod;
                tmp = 1ll*tmp*fac[x/d]%mod*ifac[x/d-2]%mod;
                chsub(S,1ll*tmp*n%mod);
            }
            return pii{S,C};
        };
        int P = 0, Q = 0;
        rep(d,1,g) if(g%d==0)
        {
            auto [a,b] = solve(d);
            chadd(P,1ll*a*phi[d]%mod);
            chadd(Q,1ll*b*phi[d]%mod);
        }
        printf("%lld\n",1ll*P*qp(Q,mod-2)%mod);
    }
    return 0;
}