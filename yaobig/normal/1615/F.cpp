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

const int maxn = 2010;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

char s[maxn+5],t[maxn+5];
int dp[maxn+5][maxn+5],cnt[maxn+5][maxn+5];
int pres[maxn+5],pret[maxn+5];

inline void chadd(int &x,const int &y) {x+=y; if(x>=mod) x-=mod;}
inline void chsub(int &x,const int &y) {x-=y; if(x<0) x+=mod;}

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n; scanf("%d",&n);
        scanf("%s",s+1);
        scanf("%s",t+1);
        rep(i,1,n) s[i] = s[i]=='0' ? 0 : s[i]=='1' ? 1 : -1;
        rep(i,1,n) t[i] = t[i]=='0' ? 0 : t[i]=='1' ? 1 : -1;
        rep(i,1,n) if(s[i]>=0 && i&1) s[i] ^= i&1;
        rep(i,1,n) if(t[i]>=0 && i&1) t[i] ^= i&1;
        n++;
        s[n] = t[n] = 1;
        rep(i,1,n) pres[i] = s[i]==1 ? i : pres[i-1];
        rep(i,1,n) pret[i] = t[i]==1 ? i : pret[i-1];
        rep(i,0,n) cnt[0][i] = 1;
        rep(i,1,n)
        {
            int l = pres[i-1];
            rep(j,1,n)
            {
                int r = pret[j-1];
                int ways = dp[i-1][j-1], C = cnt[i-1][j-1];
                if(l>0) chsub(ways, dp[l-1][j-1]), chsub(C, cnt[l-1][j-1]);
                if(r>0) chsub(ways, dp[i-1][r-1]), chsub(C, cnt[i-1][r-1]);
                if(l>0 && r>0) chadd(ways, dp[l-1][r-1]), chadd(C, cnt[l-1][r-1]);
                if(s[i]!=0 && t[j]!=0) dp[i][j] = (ways+1ll*C*abs(i-j))%mod, cnt[i][j] = C;
                else dp[i][j] = cnt[i][j] = 0;
                //debug(i,j, dp[i][j], cnt[i][j]);
            }
            dp[i][0] = cnt[i][0] = 0;
            rep(j,1,n) chadd(dp[i][j],dp[i][j-1]), chadd(cnt[i][j],cnt[i][j-1]);
            rep(j,0,n) chadd(dp[i][j],dp[i-1][j]), chadd(cnt[i][j],cnt[i-1][j]);
        }
        printf("%lld\n",(1ll*dp[n][n]-dp[n-1][n]-dp[n][n-1]+dp[n-1][n-1]+mod+mod)%mod);
    }
    return 0;
}