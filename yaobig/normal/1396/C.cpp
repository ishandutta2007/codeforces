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
const int mod = 1073741824;

int main()
{
    int n,r1,r2,r3,d; scanf("%d%d%d%d%d",&n,&r1,&r2,&r3,&d);
    static int a[maxn+5];
    rep(i,1,n) scanf("%d",&a[i]);
    vector<ll> dp{0,1ll<<60};
    rep(i,1,n)
    {
        vector<ll> ndp(2,1ll<<60);
        ll c1 = 1ll*a[i]*r1+r3;
        ll c2 = min(1ll*(a[i]+2)*r1, 1ll*r2+r1);
        chmin(ndp[0], dp[0]+c1);
        chmin(ndp[0], dp[1]+c2);
        chmin(ndp[1], dp[0]+c2+2ll*d);
        chmin(ndp[1], dp[1]+c2+2ll*d);
        if(i==n) chmin(ndp[0], dp[1]+c1-d);
        swap(dp, ndp);
    }
    ll ans = dp[0] + 1ll*d*(n-1);
    printf("%lld\n",ans);
    return 0;
}