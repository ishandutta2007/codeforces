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

const int maxn = 100;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int a[maxn+5];
char s[maxn+5];
ll dp[maxn+5][maxn+5][maxn+5];

ll dfs(int l,int r,int x)
{
    if(l>r) return 0;
    if(l==r) return a[x];
    
    ll &res = dp[l][r][x];
    if(res!=-1) return res;
    res = dfs(l,r-1,1)+a[x]; // cut the tail.
    rep(i,l,r-1) if(s[i]==s[r]) chmax(res,dfs(l,i,1+x)+dfs(i+1,r-1,1)); // glue the tail to some prefix ending with same color.
    return res;
}

int main()
{
    int n; scanf("%d",&n);
    scanf("%s",s+1);
    rep(i,1,n) scanf("%d",&a[i]);
    memset(dp,-1,sizeof dp);
    printf("%lld\n",dfs(1,n,1));
    return 0;
}