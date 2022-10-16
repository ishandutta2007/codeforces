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

const int maxn = 100000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

namespace tarjan
{
    vi e[maxn+5],pool[maxn+5];
    array<int,maxn+5> sta,dfn,low,scc;
    int cnt,tot,top,n;
    void init(int _n)
    {
        n = _n;
        rep(i,1,n) e[i].clear();
    }
    void dfs(int now)
    {
        dfn[now]=low[now]=++cnt;
        sta[++top]=now;
        for(auto v: e[now])
        {
            if(dfn[v]==0)
            {
                dfs(v);
                chmin(low[now],low[v]);
            }
            else if(scc[v]==0) chmin(low[now],dfn[v]);
        }
        if(low[now]==dfn[now])
        {
            tot++;
            while(sta[top]!=now) scc[sta[top--]]=tot;
            scc[sta[top--]]=tot;
        }
    }
    void solve()
    {
        cnt = tot = 0;
        rep(i,1,n) dfn[i] = scc[i] = 0;
        rep(i,1,n) if(dfn[i]==0) dfs(i);
        rep(i,1,tot) pool[i].clear();
        rep(i,1,n) pool[scc[i]].pb(i);
    }
};
using tarjan::e;

char s[maxn+5][55];

int main()
{
    int n,m,d; scanf("%d%d%d",&n,&m,&d);
    tarjan::init(n);
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
    }
    rep(i,1,n) scanf("%s",s[i]);
    tarjan::solve();
    using tarjan::scc;
    using tarjan::pool;
    int N = tarjan::tot;
    static ll ok[maxn+5];
    static int period[maxn+5],off[maxn+5];
    static int val[maxn+5][55],dp[maxn+5][55];
    rep(i,1,N)
    {
        int st = *pool[i].begin();
        ok[st] = 1;
        queue<int> q;
        static int mark[maxn+5];
        q.push(st); mark[st] = 1;
        while(sz(q))
        {
            int now = q.front(); q.pop(); mark[now] = 0;
            ll nmsk = ((ok[now]<<1) | (ok[now]>>(d-1))) & ((1ll<<d)-1);
            for(auto v: e[now]) if(scc[v]==i && ok[v]!=(ok[v]|nmsk)) 
            {
                ok[v] |= nmsk;
                if(mark[v]==0)
                {
                    q.push(v);
                    mark[v] = 1;
                }
            }
        }
        period[i] = d/__builtin_popcountll(ok[st]);
        for(auto now: pool[i]) off[now] = __builtin_ctzll(ok[now]);
        int M = period[i];
        for(auto now: pool[i]) 
        {
            int tmp[55] = {};
            rep(day,0,d-1) if(s[now][day]=='1') tmp[day%M] = 1;
            rep(day,0,M-1) val[i][day] += tmp[(day+off[now])%M];
        }
    }
    memset(dp,0x80,sizeof dp);
    int o = (period[scc[1]] - off[1]) % period[scc[1]];
    dp[scc[1]][o] = 0;
    int ans = 0;
    per(i,1,N) 
    {
        int M = period[i];
        rep(j,0,M-1) dp[i][j] += val[i][j], chmax(ans,dp[i][j]);
        for(auto now: pool[i]) for(auto v: e[now]) if(scc[v]!=i) 
        {
            int j = scc[v], M2 = period[j];
            rep(day,0,d-1)
            {
                int m1 = (day-off[now]+M)%M;
                int m2 = (day+1-off[v]+M2)%M2;
                chmax(dp[j][m2],dp[i][m1]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}