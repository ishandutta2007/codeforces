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

const int MAXA = 15;
const int maxn = MAXA*MAXA;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int dp[105][maxn+5];
inline int sqr(int x) {return x*x;}

int main()
{
    dp[0][0] = 1;
    rep(cur,1,100)
    {
        int old = cur-1;
        rep(i,0,maxn) if(dp[old][i]) rep(x,1,MAXA) if(i+sqr(x)<=maxn) dp[cur][i+sqr(x)] = x;
    }
    int n,m; scanf("%d%d",&n,&m);
    auto getans = [&](int N) {
        int now = -1;
        rep(x,1,MAXA) if(dp[N][sqr(x)]) {now = sqr(x); break;}
        assert(now!=-1);
        vi res;
        while(N)
        {
            res.pb(dp[N][now]);
            now -= sqr(dp[N][now]);
            N--;
        }
        assert(now==0);
        return res;
    };
    auto X = getans(n);
    auto Y = getans(m);
    rep(i,1,n) rep(j,1,m) printf("%d%c",X[i-1]*Y[j-1]," \n"[j==m]);
    return 0;
}