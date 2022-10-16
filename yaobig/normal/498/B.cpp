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

const int maxn = 5000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

db dp[2][maxn+5];

int main()
{
    int n,T; scanf("%d%d",&n,&T);
    int cur = 0;
    dp[cur][0] = 1.0;
    db ans = 0;
    rep(_,1,n)
    {
        int x,t; scanf("%d%d",&x,&t);
        db p = x/100.0;
        db A = 0, pw = p;
        rep(i,1,t-1)
        {
            A += pw;
            pw *= 1-p;
        }
        A = 1-A;
        int old = cur; cur ^= 1;
        db sum = 0;
        dp[cur][0] = 0;
        rep(i,1,T)
        {
            sum = sum*(1-p)+dp[old][i-1]*p;
            if(i>=t) sum -= dp[old][i-t]*pw;
            dp[cur][i] = sum + (i>=t ? dp[old][i-t]*A : 0);
        }
        rep(i,0,T) ans += dp[cur][i];
    }
    printf("%.9f\n",ans);
    return 0;
}