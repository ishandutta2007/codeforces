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

const int maxn = 2'000;
const int inf = 0x3f3f3f3f;
const int mod = 1073741824;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,int y) {x-=y; if(x<0) x+=mod;}

int G[maxn+5][maxn+5];

int main()
{
    static int maxp[maxn+5];
    rep(i,2,maxn) if(maxp[i]==0) for(int j=i;j<=maxn;j+=i) maxp[j] = i;
    
    static int mu[maxn+5];
    mu[1] = 1;
    rep(i,2,maxn)
    {
        int p = maxp[i];
        mu[i] = maxp[i/p]==p ? 0 : -mu[i/p];
    }

    rep(i,1,maxn) rep(j,1,maxn) G[i][j] = __gcd(i,j);

    int ans = 0;
    int a,b,c; scanf("%d%d%d",&a,&b,&c);
    rep(k,1,c)
    {
        int cp = c/k;
        rep(d,1,min(a,b)) if(mu[d]!=0)
        {
            int sa = 0, sb = 0;
            rep(i,1,a/d) if(G[k][i*d]==1) chadd(sa, a/d/i);
            rep(j,1,b/d) if(G[k][j*d]==1) chadd(sb, b/d/j);
            int val = 1ll*sa*sb%mod*cp%mod;
            mu[d]==1 ? chadd(ans, val) : chsub(ans, val);
        }
    }
    printf("%d\n",ans);
    return 0;
}