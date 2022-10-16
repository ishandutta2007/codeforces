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

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

template<class T> T exgcd(T a,T b,T &x,T &y) 
{
    if(!b) {x=1;y=0;return a;}
    T G=exgcd(b,a%b,x,y);
    T tmp=x;
    x=y;y=tmp-a/b*y;
    return G;
}
int ban[maxn+5];
vi pool[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n)
    {
        int x; scanf("%d",&x); ban[x] = 1;
    }
    rep(i,0,m-1) if(ban[i]==0) pool[__gcd(i,m)].pb(i);
    static int dp[maxn+5],from[maxn+5];
    rep(i,1,m)
    {
        dp[i] += sz(pool[i]);
        for(int j = i*2; j<=m; j += i) if(chmax(dp[j],dp[i])) from[j] = i;
    }
    vi ans;
    for(int i = m; i; i = from[i]) for(auto x: pool[i]) ans.pb(x);
    reverse(all(ans));
    printf("%d\n",sz(ans));
    int last = 1;
    for(auto b: ans) 
    {
        int x,y; int g = exgcd(last,m,x,y);
        if(x<0) x += m;
        x = 1ll*x*(b/g)%m;
        last = b;
        printf("%d%c",x," \n"[b==ans.back()]);
    }
    return 0;
}