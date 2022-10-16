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

int cnt[maxn+5];
int dp[maxn+5][maxn*maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        int x; scanf("%d",&x); cnt[x]++;
    }
    int diff = 0;
    rep(i,1,100) if(cnt[i]) diff++;
    if(diff<=2) return printf("%d\n",n),0;
    int ans = 0;
    rep(x,1,100) if(cnt[x])
    {
        int N = cnt[x];
        rep(i,0,N) rep(j,0,N*x) dp[i][j]=0;
        dp[0][0]=1;
        rep(y,1,100) if(y!=x && cnt[y]) rep(_,1,cnt[y])
        {
            per(i,0,N-1) per(j,0,N*x-y) dp[i+1][j+y] |= dp[i][j];
        }
        int mx = 0;
        rep(i,1,N) 
        {
            if(dp[i][i*x]==0) mx = i;
            else break;
        }
        chmax(ans,mx);
    }
    printf("%d\n",ans);
    return 0;
}