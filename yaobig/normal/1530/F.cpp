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

const int maxn = 23;
const int inf = 0x3f3f3f3f;
const int mod = 31607;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,int y) {x-=y; if(x<0) x+=mod;}

ll qp(ll a,ll k)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%mod) if(k&1) res = res*a%mod;
    return res;
}

int main()
{
    int n; scanf("%d",&n);
    static int p[maxn+5][maxn+5];
    rep(i,0,n-1) rep(j,0,n-1) scanf("%d",&p[i][j]), p[i][j] = 1ll*p[i][j]*qp(10000,mod-2)%mod;
    int N = 1<<(n+2);
    vi a(N,1);
    rep(i,0,n-1) 
    {
        vi b(N);
        int M = 1<<n;
        b[0] = 1;
        rep(msk,1,M-1) 
        {
            int j = __builtin_ctz(msk);
            b[msk] = b[msk^(1<<j)]*p[i][j]%mod;
        }
        int pos1 = i, pos2 = n-1-i;
        rep(msk,M,N-1)
        {
            int smsk = msk & (M-1), bit1 = msk>>n&1, bit2 = msk>>(n+1)&1;
            b[msk] = b[smsk | (bit1<<pos1) | (bit2<<pos2)];
        }
        int all = 1;
        rep(j,0,n-1) all = all*p[i][j]%mod;
        rep(msk,0,N-1) chsub(b[msk], all);
        rep(msk,0,N-1) a[msk] = a[msk]*b[msk]%mod;
    }
    rep(i,0,n+1) rep(msk,0,N-1) if((msk>>i&1)==0) chsub(a[msk], a[msk^(1<<i)]);
    int ans = 1;
    chsub(ans, a[0]);
    printf("%d\n",ans);
    return 0;
}