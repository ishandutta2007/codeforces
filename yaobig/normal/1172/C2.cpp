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

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

const int MAXM = 3000;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

ll qp(ll a,ll k)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%mod) if(k&1) res=res*a%mod;
    return res;
}

int like[maxn+5],w[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&like[i]);
    rep(i,1,n) scanf("%d",&w[i]);
    int sum = 0, A = 0, B = 0;
    rep(i,1,n) sum += w[i];
    rep(i,1,n) if(like[i]==0) A += w[i]; else B += w[i];

    static int f[MAXM+5][MAXM+5];
    static int g[MAXM+5][MAXM+5];
    static int iv[MAXM*2+15];
    rep(i,-m,m) iv[i+m] = qp(sum+i,mod-2);
    rep(x,0,m) f[0][x] = 1, g[0][x] = x<A;
    rep(i,1,m) rep(x,0,m-i) if(x<=A)
    {
        int y = m-i-x;
        int inv = iv[m-x+y];
        f[i][x] = (1ll*(A-x)*f[i-1][x+1] + 1ll*(B+y+1)*f[i-1][x])%mod*inv%mod;
        g[i][x] = (1ll*(A-x-(x!=A))*g[i-1][x+1] + 1ll*(B+y)*g[i-1][x])%mod*inv%mod;
    }
    rep(i,1,n)
    {
        if(like[i]) printf("%lld\n",1ll*f[m][0]*w[i]%mod);
        else printf("%lld\n",1ll*g[m][0]*w[i]%mod);
    }
    return 0;
}