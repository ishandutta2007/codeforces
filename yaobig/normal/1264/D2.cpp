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

const int maxn = 1'000'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,int y) {x-=y; if(x<0) x+=mod;}

int fac[maxn+5],ifac[maxn+5],inv[maxn+5];
int binom(int n,int m)
{
    if(m<0 || n<m) return 0;
    return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

char s[maxn+5];

int main()
{
    inv[1] = fac[0] = ifac[0] = 1;
    rep(i,2,maxn) inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i] = 1ll*fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i] = 1ll*ifac[i-1]*inv[i]%mod;
    
    scanf("%s",s+1);
    int n = strlen(s+1);
    
    static int ps0[maxn+5],ps1[maxn+5],psq[maxn+5];
    rep(i,1,n) ps0[i] = ps0[i-1] + (s[i]=='(');
    rep(i,1,n) ps1[i] = ps1[i-1] + (s[i]==')');
    rep(i,1,n) psq[i] = psq[i-1] + (s[i]=='?');
    
    int tot = psq[n];
    static int pscom[2][maxn+5];
    rep(r,0,1) rep(i,0,tot) pscom[r][i] = binom(tot-r,i);
    rep(r,0,1) rep(i,1,tot) chadd(pscom[r][i], pscom[r][i-1]);

    int ans = 0;
    rep(i,1,n) if(s[i]=='(' || s[i]=='?')
    {
        int isq = s[i]=='?';
        int a = ps0[i-1], b = ps1[n] - ps1[i];
        int d = psq[n] - psq[i];
        int cnt = b+d-a<=0 ? 0 : pscom[isq][min(b+d-a-1,tot)];
        chadd(ans, cnt);
    }
    printf("%d\n",ans);
    return 0;
}