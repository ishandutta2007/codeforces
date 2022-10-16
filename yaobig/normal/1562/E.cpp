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
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}

void debug_out() {cerr << endl;} 
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 5000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

char s[maxn+5];
int lcp[maxn+5][maxn+5];
int dp[maxn+5];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        scanf("%s",s+1);
        rep(i,1,n)
        {
            lcp[i][n+1]=0;
            rep(j,1,i-1) lcp[i-j][n+1-j] = s[i-j]==s[n+1-j] ? 1+lcp[i-j+1][n+1-j+1] : 0;
        }
        per(i,1,n)
        {
            dp[i] = n-i+1;
            rep(j,i+1,n)
            {
                int l = lcp[i][j];
                if(s[i+l]<s[j+l]) chmax(dp[i],dp[j] + n-i+1 - l);
            }
        }
        int ans=0;
        rep(i,1,n) chmax(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}