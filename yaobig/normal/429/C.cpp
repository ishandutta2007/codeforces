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

const int maxn = 24;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int a[maxn+5];

bool solve()
{
    int n; scanf("%d",&n);
    int tot = 0, one = 0;
    rep(i,1,n) 
    {
        int x; scanf("%d",&x);
        if(x==1) one++;
        else a[++tot] = x;
    }
    if(n==1) return tot==0;
    if(tot==0) return 0;
    if(one<(n+2)/2) return 0;
    rep(i,1,tot) if(a[i]==2) return 0;
    sort(a+1,a+tot+1,greater<int>());
    static int sz[maxn+5];
    function<bool(int)> dfs = [&](int dep) {
        if(dep>tot)
        {
            int cnt = 0;
            rep(i,1,tot) cnt += a[i]-sz[i];
            return cnt==one;
        }
        sz[dep] = 1;
        rep(i,1,dep-1) if(a[dep]<a[i]-1 && sz[i]+a[dep]<=a[i])
        {
            sz[i] += a[dep];
            if(dfs(dep+1)) return true;
            sz[i] -= a[dep];
        }
        return false;
    };
    sz[1] = 1;
    return dfs(2);
}

int main()
{
    puts(solve()?"YES":"NO");
    return 0;
}