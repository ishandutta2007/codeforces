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

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int a[maxn+5],b[maxn+5];
vi pool[maxn+5];

int dp[305];

int main()
{
    int n,m,s,e; scanf("%d%d%d%d",&n,&m,&s,&e);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,m) scanf("%d",&b[i]);
    rep(i,1,m) pool[b[i]].pb(i);
    int L = s/e;
    
    // dp[i][j] = minimum k such that LCS(a[1...i],b[1...k]) = j. We drop i in the dp array.
    memset(dp,0x3f,sizeof dp);
    dp[0] = 0;
    int ans = 0;
    rep(i,1,n)
    {
        int x = a[i];
        per(j,1,L) 
        {
            auto it = upper_bound(all(pool[x]),dp[j-1]);
            int pos = it==pool[x].end() ? inf : *it;
            chmin(dp[j], pos);
            if(j*e+i+pos<=s) chmax(ans,j);
        }
    }
    printf("%d\n",ans);
    return 0;
}