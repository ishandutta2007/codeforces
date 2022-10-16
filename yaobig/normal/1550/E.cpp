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
template <typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x : v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
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

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

char s[maxn+5];
int nxt[17][maxn+5];
int cnt[maxn+5];

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    scanf("%s",s+1);

    auto check = [&](int len)
    {
        rep(ch,0,k-1)
        {
            rep(i,1,n) cnt[i] = cnt[i-1] + (s[i]=='?' || s[i]=='a'+ch);
            rep(i,n-len+1,n) nxt[ch][i] = inf;
            per(i,0,n-len)
            {
                int ok = (cnt[i+len]-cnt[i]==len);
                nxt[ch][i] = ok ? i+1 : nxt[ch][i+1];
            }
        }
        int N = 1<<k;
        vi dp(N,inf);
        dp[0] = 0;
        rep(msk,1,N-1) rep(i,0,k-1) if(msk>>i&1)
        {
            int omsk = msk ^ (1<<i);
            int L = dp[omsk];
            if(L>=n) continue;
            chmin(dp[msk], nxt[i][L] + len-1);
        }
        return dp[N-1]<=n;
    };

    int l=1,r=n+1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    printf("%d\n",l-1);
    return 0;
}