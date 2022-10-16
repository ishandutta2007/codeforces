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

const int maxn = 1'000'000;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int main()
{
    int n; scanf("%d",&n);
    static vi e[maxn+5];
    rep(i,2,n) 
    {
        int f; scanf("%d",&f);
        e[i].pb(f);
        e[f].pb(i);
    }
    int mn = inf, cent = -1;
    function<int(int,int)> getcent = [&](int now,int fa)
    {
        int sz = 1;
        int mx = 0;
        for(auto v: e[now]) if(v!=fa)
        {
            int szv = getcent(v,now);
            sz += szv;
            chmax(mx, szv);
        }
        chmax(mx, n-sz);
        if(chmin(mn, mx)) cent = now;
        return sz;
    };
    getcent(1,0);
    
    ll ans = n;
    function<int(int,int,int)> dfs = [&](int now,int fa,int dep)
    {
        ans += dep;
        int sz = 1;
        for(auto v: e[now]) if(v!=fa) sz += dfs(v,now,dep+1);
        return sz;
    };

    static int cnt[maxn+5];
    for(auto v: e[cent]) cnt[dfs(v,cent,1)]++;
    rep(i,1,n) if(cnt[i]>1) 
    {
        int x = (cnt[i]-1)/2;
        cnt[i*2] += x;
        cnt[i] -= x*2;
    }
    using bs = bitset<maxn+5>;
    bs dp; dp[0] = 1;
    rep(i,1,n) while(cnt[i]--) dp |= dp << i;
    ll mx = 0;
    rep(i,0,n-1) if(dp[i]) chmax(mx, 1ll*i*(n-1-i));
    ans += mx;
    printf("%lld\n",ans);
    return 0;
}