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

const int maxn = 1<<20;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

vi e[45];
ll adj[45];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    if(m==0) return puts("0"),0;
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
        x--; y--;
        adj[x] |= 1ll<<y;
        adj[y] |= 1ll<<x;
    }

    // use inclusion-exclusion to calculate the answer.
    // no 0-0 and no 1-1 are actually same: flip the color of each vertex, use bitmask to calculate.
    // no 0-1: vertices in each connected component have same color.
    // no 0-0 or 0-1 => all 1-1: vertices in each connected component of size > 1 should have color 1.
    // no 1-1 or 0-1 => all 0-0, same as above: flip the color of each vertex.
    // no 0-0 or 1-1 => all 0-1: need to be bipartite and the answer is 2^{# of components}.

    int L = n/2, R = n-L;
    int N = 1<<L, M = 1<<R;
    static int dp[maxn];
    rep(msk,0,M-1)
    {
        int ok = 1;
        rep(i,0,R-1) if(msk>>i&1)
        {
            auto tmp = adj[i+L]>>L;
            if(msk & tmp) ok = 0;
        }
        dp[msk] = ok;
    }
    rep(i,0,R-1) rep(msk,0,M-1) if(msk>>i&1) dp[msk] += dp[msk ^ (1<<i)];
    ll cnt_no11 = 0;
    rep(msk,0,N-1)
    {
        int ok = 1;
        rep(i,0,L-1) if(msk>>i&1)
        {
            auto tmp = adj[i];
            if(msk & tmp) ok = 0;
        }
        if(ok)
        {
            ll ban = 0;
            rep(i,0,L-1) if(msk>>i&1) ban |= adj[i]>>L;
            auto can = (M-1) ^ ban;
            cnt_no11 += dp[can];
        }
    }
    
    int com = 0, iso = 0, bip = 1;
    static int clr[45];
    memset(clr,-1,sizeof clr);
    rep(i,1,n) if(clr[i]==-1)
    {
        int cnt = 0;
        function<void(int,int)> dfs = [&](int now,int c) {
            clr[now] = c;
            cnt++;
            for(auto v: e[now]) 
            {
                if(clr[v]!=-1) bip &= clr[v]^clr[now];
                else dfs(v,c^1);
            }
        };
        dfs(i,0);
        com++;
        iso += cnt==1;
    }
    ll ans = 1ll<<n; 
    ans -= cnt_no11*2;
    ans -= 1ll<<com;
    ans += 2ll<<iso;
    if(bip) ans += 1ll<<com;
    printf("%lld\n",ans);
    return 0;
}