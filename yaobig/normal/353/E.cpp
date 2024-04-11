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

const int maxn = 2'000'000;
const int inf = 0x3f3f3f3f;
const int mod = 1'000'000'007;

char s[maxn+5];

int main()
{
    scanf("%s",s+1);
    int n = strlen(s+1);
    rep(i,1,n) s[i+n] = s[i];
    static int pre[maxn+5];
    rep(i,1,n*2) pre[i] = i>1 && s[i]==s[i-1] ? pre[i-1] : i;
    auto solve = [&](int l,int r) {
        static int dp[maxn+5];
        int mx = 0, ptr = l-1, res = 0;
        rep(i,l,r)
        {
            while(ptr+1<pre[i-1]) chmax(mx, dp[++ptr]);
            dp[i] = mx+1;
            chmax(res, dp[i]);
        }
        return res;
    };
    int st = pre[n], ans = 0;
    chmax(ans, solve(st+1,st+n-1));
    int l = st;
    while(s[st]==s[l]) l++;
    chmax(ans, solve(l+1,pre[st+n-1]-1)+1);
    printf("%d\n",ans);
    return 0;
}