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

const int maxn = 300000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int maxp[maxn+5],mu[maxn+5];

int main()
{
    rep(i,2,maxn) if(maxp[i]==0) for(int j=i;j<=maxn;j+=i) maxp[j] = i;
    mu[1] = 1;
    rep(i,2,maxn)
    {
        int p = maxp[i];
        if(maxp[i/p]==p) mu[i] = 0;
        else mu[i] = -mu[i/p];
    }

    static int cnt[maxn+5],dp[maxn+5];
    int n; scanf("%d",&n);
    rep(i,1,n) {int x; scanf("%d",&x); cnt[x]++;}
    rep(i,1,maxn) dp[i] = cnt[i]>0 ? 1 : inf;
    rep(i,1,maxn) if(maxp[i]==i) per(j,1,maxn/i) cnt[j] += cnt[j*i];

    static int ok[maxn+5]; // we have ok[i] = sum_{j: j|i} cnt[j]*mu[j].
    rep(i,1,maxn) if(mu[i]!=0) for(int j=i;j<=maxn;j+=i) ok[j] += cnt[i]*mu[i];
    per(i,1,maxn) for(int j=i*2;j<=maxn;j+=i) if(ok[j/i]) chmin(dp[i],dp[j]+1);
    if(dp[1]==inf) puts("-1");
    else printf("%d\n",dp[1]);
    return 0;
}