#include "bits/stdc++.h"
#define rep(i, a, n) for(auto i = a; i <= (n); i++)
#define per(i, a, n) for(auto i = n; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if(b < a) { a = b; return 1; } return 0; }
using namespace std;

template<class A, class B> string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<class A> string to_string(A v)
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
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")"; }

void debug_out() { cerr << endl; }
template<class Head, class... Tail> void debug_out(Head H, Tail... T) 
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
// using LL = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using db = double;
using ldb = long double;

const int maxn = 400'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

struct TwoSat
{   // 0-based indexing.
    int n;
    vector<vi> e;
    vector<bool> ans;
    TwoSat(int n): n(n), e(n * 2), ans(n) {}

    void addclause(int x, int f, int y, int g)
    {   // e.g. if you want to add clause (not x) or (y), just call addclause(x, 0, y, 1);
        e[x * 2 + !f].pb(y * 2 + g);
        e[y * 2 + !g].pb(x * 2 + f);
    }
    bool solve()
    {
        vi id(n * 2, -1), dfn(n * 2, -1), low(n * 2, -1), sta;
        int cnt = 0, scc = 0;
        function<void(int)> dfs = [&](int now)
        {
            dfn[now] = low[now] = cnt++;
            sta.pb(now);
            for(auto v: e[now])
            {
                if(dfn[v] == -1)
                {
                    dfs(v);
                    chmin(low[now], low[v]);
                }
                else if(id[v] == -1) chmin(low[now], dfn[v]);
            }
            if(low[now] == dfn[now])
            {
                while(sta.back() != now) id[sta.back()] = scc, sta.pop_back();
                id[sta.back()] = scc, sta.pop_back();
                scc++;
            }
        };
        
        rep(i, 0, n * 2 - 1) if(dfn[i] == -1) dfs(i);
        rep(i, 0, n - 1)
        {
            if(id[i * 2] == id[i * 2 + 1]) return 0;
            ans[i] = id[i * 2] > id[i * 2 + 1];
        }
        return 1;
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    vvi e(n);
    vi dep(n), par(n, -1);
    rep(i, 1, n - 1)
    {
        int x, y; cin >> x >> y; x--, y--;
        e[x].pb(y);
        e[y].pb(x);
    }
    function<void(int, int)> dfs = [&](int now, int fa)
    {
        for(auto v: e[now]) if(v != fa) 
        {
            dep[v] = dep[now] + 1;
            par[v] = now;
            dfs(v, now);
        }
    };
    dfs(0, -1);

    auto getpath = [&](int u, int v)
    {
        vi l, r;
        while(u != v)
        {
            if(dep[u] > dep[v]) l.pb(u), u = par[u];
            else r.pb(v), v = par[v];
        }
        l.pb(u);
        reverse(all(r));
        l.insert(l.end(), all(r));
        return l;
    };

    static char cand[maxn][2];
    rep(i, 0, n - 1) cand[i][0] = cand[i][1] = 'a';

    struct node {int u, v; string s; vi path;};
    vector<node> qs(q);
    for(auto &[u, v, s, path]: qs)
    {
        cin >> u >> v >> s; u--, v--;
        path = getpath(u, v);
        int l = sz(path);
        rep(i, 0, l - 1)
        {
            int now = path[i];
            cand[now][0] = s[i];
            cand[now][1] = s[l - 1 - i];
        }
    }

    TwoSat ts(n + q);
    int tot = n;
    for(auto &[u, v, s, path]: qs)
    {
        int var = tot++;
        int l = sz(path);
        rep(i, 0, l - 1)
        {
            int now = path[i];
            rep(j, 0, 1) 
            {
                if(cand[now][j] != s[i]) ts.addclause(now, !j, var, !0);
                if(cand[now][j] != s[l - 1 - i]) ts.addclause(now, !j, var, !1);
            }
        }
    }
    if(ts.solve() == 0) puts("NO");
    else
    {
        puts("YES");
        auto &res = ts.ans;
        rep(i, 0, n - 1) putchar(cand[i][res[i]]);
    }
    return 0;
}