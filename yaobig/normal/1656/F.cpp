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
string to_string(bool b) {return (b ? "true" : "false");}
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

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        static int a[maxn+5];
        rep(i,1,n) scanf("%d",&a[i]);
        sort(a+1,a+n+1);

        int INF = 0;
        ll ans = -1ll<<60;
        // t > -a_1
        ll A = 0, B = 0;
        rep(i,2,n) A += 1ll*a[1]*a[i], B += a[1]+a[i];
        if(B>0) INF = 1;
        else chmax(ans, A + 1ll*(-a[1])*B);
        // t < -a_n
        A = B = 0;
        rep(i,1,n-1) A += 1ll*a[n]*a[i], B += a[n]+a[i];
        if(B<0) INF = 1;
        else chmax(ans, A + 1ll*(-a[n])*B);
        
        if(INF) puts("INF");
        else
        {
            ll ps = a[1], ss = 0;
            rep(i,2,n) ss += a[i];
            rep(i,2,n)
            {
                // -a_i < t < -a_{i-1}
                ll A = 1ll*ps*a[n] + 1ll*ss*a[1] - 1ll*a[1]*a[n];
                ll B = ps + 1ll*(i-1)*a[n] + ss + 1ll*(n-i+1)*a[1] - a[1] - a[n];
                chmax(ans, A + 1ll*(-a[i])*B);
                chmax(ans, A + 1ll*(-a[i-1])*B);
                ps += a[i]; ss -= a[i];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}