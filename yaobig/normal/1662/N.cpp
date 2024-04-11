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
string to_string(char c) {return "'" + string(1,c) + "'";}
string to_string(bool x) {return x ? "true" : "false";}
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

const int maxn = 1'500;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;


int main()
{
    int n; scanf("%d",&n);
    static int a[maxn+5][maxn+5];
    static int small_row[maxn+5][maxn+5];
    static int small_col[maxn+5][maxn+5];
    rep(i,1,n) rep(j,1,n) scanf("%d",&a[i][j]);
    rep(i,1,n)
    {
        vi vec(n);
        rep(j,1,n) vec[j-1] = j;
        sort(all(vec),[&](int x,int y){return a[i][x] < a[i][y];});
        int tot = 0;
        for(auto j: vec) small_row[i][j] = tot++;
    }
    rep(j,1,n)
    {
        vi vec(n);
        rep(i,1,n) vec[i-1] = i;
        sort(all(vec),[&](int x,int y){return a[x][j] < a[y][j];});
        int tot = 0;
        for(auto i: vec) small_col[i][j] = tot++;
    }
    ll ans = 0;
    rep(i,1,n) rep(j,1,n) 
    {
        ans += 1ll*small_row[i][j]*(n-1-small_col[i][j]);
        ans += 1ll*small_col[i][j]*(n-1-small_row[i][j]);
    }
    assert(ans%2==0);
    ans /= 2;
    printf("%lld\n",ans);
    return 0;
}