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

const int maxn = 1000000;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,const int &y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,const int &y) {x-=y; if(x<0) x+=mod;}

char s[maxn+5];
int dp[maxn+5];

int main()
{
    scanf("%s",s+1);
    int n = strlen(s+1);
    static int dis[maxn+5],nxt[maxn+5];
    rep(i,0,n) nxt[i] = n+1;
    rep(i,1,n) dis[i] = s[i]=='1' ? 0 : dis[i-1]+1;
    per(i,1,n)
    {
        int d = dis[i];
        dp[i] = d<=dis[n]; // if you can end at i.
        if(nxt[d+1]<=n) chadd(dp[i],dp[nxt[d+1]]); // if you can add a 0 to the end.
        if(nxt[0]<=n) chadd(dp[i],dp[nxt[0]]); // if you can add a 1 to the end.
        nxt[d] = i;
    }
    if(dis[n]==n) printf("%d\n",n);
    else printf("%lld\n",1ll*dp[nxt[0]]*nxt[0]%mod); // the first 1 can not be avoided.
    return 0;
}