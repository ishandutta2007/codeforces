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

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int main()
{
    static vi to[maxn+5];
    static int a[maxn+5],ans[maxn+5];
    static int x[maxn+5],y[maxn+5];

    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    int m; scanf("%d",&m);
    rep(i,1,m) 
    {
        scanf("%d%d",&x[i],&y[i]);
        to[x[i]].pb(i);
        to[y[i]].pb(i);
    }

    static int dep[maxn+5];
    function<int(int,int)> dfs = [&](int now,int fa) {
        dep[now] = dep[fa]+1;
        int sum = a[now];
        for(auto i: to[now])
        {
            int v = now^x[i]^y[i];
            if(dep[v]==0) 
            {
                int res = dfs(v,now);
                sum += res;
                ans[i] = now==x[i] ? res : -res;
            }
        }
        return sum;
    };
    int res = dfs(1,0);
    if(res) puts("Impossible");
    else
    {
        puts("Possible");
        rep(i,1,m) printf("%d\n",ans[i]);
    }
    return 0;
}