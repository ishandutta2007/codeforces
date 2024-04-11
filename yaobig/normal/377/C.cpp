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

const int maxn = 1<<20;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int a[105];
char op[25][10]; int team[25];
int dp[maxn];

int main()
{
    int n; scanf("%d",&n);
    rep(i,0,n-1) scanf("%d",&a[i]);
    int m; scanf("%d",&m);
    rep(i,1,m) scanf("%s%d",op[i],&team[i]);
    sort(a,a+n,greater<int>());
    int N = 1<<m;
    rep(msk,1,N-1)
    {
        int i = m+1-__builtin_popcount(msk);
        dp[msk] = team[i]==1 ? -inf : inf;
        rep(b,0,m-1) if(msk>>b&1)
        {
            int nmsk = msk ^ (1<<b);
            if(team[i]==1) chmax(dp[msk], dp[nmsk] + (op[i][0]=='p' ? a[b] : 0));
            else chmin(dp[msk], dp[nmsk] - (op[i][0]=='p' ? a[b] : 0));
        }
    }
    printf("%d\n",dp[N-1]);
    return 0;
}