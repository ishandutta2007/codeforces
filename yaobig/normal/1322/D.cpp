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
const int mod = 1'000'000'007;

int l[maxn+5],s[maxn+5],c[maxn*2+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&l[i]);
    rep(i,1,n) scanf("%d",&s[i]);
    rep(i,1,n+m) scanf("%d",&c[i]);
    static int dp[maxn+55][maxn+5]; 
    rep(i,1,m+50) rep(j,1,n) dp[i][j] = -inf;
    per(item,1,n)
    {
        int lvl = l[item], w = s[item];
        per(j,1,n) chmax(dp[lvl][j], dp[lvl][j-1]+c[lvl]-w);
        int tot = n;
        rep(i,lvl,m+49) 
        {
            rep(j,0,tot) chmax(dp[i+1][j/2], dp[i][j]+(j/2)*c[i+1]);
            tot /= 2;
        }
    }
    printf("%d\n",dp[m+50][0]);
    return 0;
}