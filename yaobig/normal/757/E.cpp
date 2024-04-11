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

const int maxn = 1000200;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

int fac[maxn+5],ifac[maxn+5],inv[maxn+5];
int binom(int n,int m)
{
    if(m<0 || n<m) return 0;
    return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

int maxp[maxn+5];

int main()
{
    inv[1] = fac[0] = ifac[0] = 1;
    rep(i,2,maxn) inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i] = 1ll*fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i] = 1ll*ifac[i-1]*inv[i]%mod;

    rep(i,2,maxn) if(maxp[i]==0) for(int j=i;j<=maxn;j+=i) chmax(maxp[j],i);

    int cas; scanf("%d",&cas); while (cas--)
    {
        int r,n; scanf("%d%d",&r,&n);
        int ans = 1;
        while(n!=1)
        {
            int p = maxp[n], cnt = 0;
            while(n%p==0) n /= p, cnt++;
            ans = 1ll*ans*(2ll*binom(cnt+r-1,r)+binom(cnt+r-1,r-1))%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}