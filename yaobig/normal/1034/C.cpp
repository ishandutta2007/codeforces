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
const int mod = 1'000'000'007;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}

ll a[maxn+5];
int p[maxn+5],cnt[maxn+5];
bool ok[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%lld",&a[i]);
    rep(i,2,n) scanf("%d",&p[i]);
    ll sum = 0;
    rep(i,1,n) sum += a[i];
    per(i,2,n) a[p[i]] += a[i];
    rep(i,1,n) 
    {
        ll x = sum / __gcd(sum,a[i]);
        if(x<=n) cnt[x]++;
    }
    per(i,1,n) for(int j=i*2;j<=n;j+=i) cnt[j] += cnt[i];
    rep(i,1,n) ok[i] = cnt[i]==i;
    static int dp[maxn+5];
    dp[1] = 1;
    rep(i,1,n) if(ok[i]) for(int j=i*2;j<=n;j+=i) chadd(dp[j],dp[i]);
    int ans = 0;
    rep(i,1,n) if(ok[i]) chadd(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}