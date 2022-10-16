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

const int maxn = 3'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

pii operator +(pii a,pii b) { return pii{a.FI + b.FI, a.SE + b.SE}; }

int main()
{
    int n,k; scanf("%d%d",&n,&k);
    static vector<int> a[maxn+5];
    static vector<ll> ps[maxn+5];
    static int w[maxn+5];
    static ll v[maxn+5];
    rep(i,1,n)
    {
        int m; scanf("%d",&m);
        a[i].resize(m);
        for(auto &x: a[i]) scanf("%d",&x);
        ps[i].assign(m+1,0);
        rep(j,0,m-1) ps[i][j+1] = ps[i][j] + a[i][j];
        w[i] = m;
        v[i] = ps[i][m];
    }

    ll ans = 0;
    function<void(int,int,vector<ll>&)> dfs = [&](int l,int r,vector<ll> &dp) {
        if(l==r)
        {
            rep(i,0,w[l]) if(i<=k) chmax(ans, dp[k-i] + ps[l][i]);
            return;
        }
        
        int mid = (l+r)>>1;
        auto &dpl = dp;
        auto dpr = dp;
        
        auto upd = [&](vector<ll> &dp,int w,ll v) {
            per(i,w,sz(dp)-1) chmax(dp[i], dp[i-w]+v);
        };
        
        rep(i,l,mid) upd(dpr, w[i], v[i]);
        rep(i,mid+1,r) upd(dpl, w[i], v[i]);
        dfs(l,mid,dpl);
        dfs(mid+1,r,dpr);
    };
    vector<ll> dum(k+1,0);
    dfs(1,n,dum);
    printf("%lld\n",ans);
    return 0;
}