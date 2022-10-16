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
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

ll qp(ll a,ll k)
{
    ll res = 1;
    for(;k;k>>=1,a=a*a%mod) if(k&1) res=res*a%mod;
    return res;
}

int main()
{
    int n,q; scanf("%d%d",&n,&q);
    static int d[maxn+5];
    static ll ps[maxn+5];
    rep(i,1,n) scanf("%d",&d[i]);
    sort(d+1,d+n+1);
    rep(i,1,n) ps[i] = ps[i-1]+d[i];
    while(q--)
    {
        int a,b; scanf("%d%d",&a,&b);
        int pos = lower_bound(d+1,d+n+1,b) - d;
        int bad = n+1-pos;
        if(bad<a) puts("0");
        else
        {
            int ans = 0;
            int p1 = 1ll*(bad+1-a)*qp(bad+1,mod-2)%mod;
            int p2 = 1ll*(bad-a)*qp(bad,mod-2)%mod;
            chadd(ans, 1ll*ps[pos-1]%mod*p1%mod);
            chadd(ans, 1ll*(ps[n]-ps[pos-1])%mod*p2%mod);
            printf("%d\n",ans);
        }
    }
    return 0;
}