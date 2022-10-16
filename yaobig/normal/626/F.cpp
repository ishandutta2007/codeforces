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

const int maxn = 200;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

inline void chadd(int &x,const int &y) {x+=y; if(x>=mod) x-=mod;}

int a[maxn+5];
int dp[2][maxn+5][1005];

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int cur = 0;
    dp[cur][0][0] = 1;
    rep(i,1,n)
    {
        int old = cur; cur ^= 1;
        rep(cnt,0,n/2) rep(sum,0,k) dp[cur][cnt][sum] = 0;
        rep(cnt,0,n/2) rep(sum,0,k) if(dp[old][cnt][sum])
        {
            int nsum = sum + cnt*(a[i]-a[i-1]), ways = dp[old][cnt][sum];
            if(nsum<=k)
            {
                chadd(dp[cur][cnt][nsum],ways); // make i a group of size 1.
                chadd(dp[cur][cnt+1][nsum],ways); // make i the minimum of a new group.
                if(cnt)
                {
                    chadd(dp[cur][cnt-1][nsum],1ll*ways*cnt%mod); // make i the maximum of an existing group.
                    chadd(dp[cur][cnt][nsum],1ll*ways*cnt%mod); // make i some noraml guy of an existing group.
                }
            }
        }
    }
    int ans = 0;
    rep(sum,0,k) chadd(ans,dp[cur][0][sum]);
    printf("%d\n",ans);
    return 0;
}