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

const int maxn = 200'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

template<class F, F F_MAX> struct Dinic
{   // 0-based indexing.
    int n;
    struct E { int v; F cap; };
    vector<E> e;
    vector<vi> g;
    Dinic(int n) : n(n), g(n) {}
    void add(int u, int v, F c)
    {
        g[u].pb(sz(e)); e.pb({v, c});
        g[v].pb(sz(e)); e.pb({u, 0});
    }
    F work(int src, int sink)
    {
        vi dis, cur;
        auto bfs = [&]()
        {
            dis.assign(n, inf);
            queue<int> q;
            q.push(src); dis[src]=0;
            while(sz(q))
            {
                int now = q.front(); q.pop();
                for(auto i: g[now])
                {
                    auto [v, c] = e[i];
                    if(c > 0 && chmin(dis[v], dis[now] + 1)) q.push(v);
                }
            }
            return dis[sink] != inf;
        };
        function<F(int, F)> dfs = [&](int now, F flow)
        {
            if(now == sink) return flow;
            F res = 0;
            for(int &id = cur[now]; id < sz(g[now]); id++)
            {
                int i = g[now][id];
                auto [v, c] = e[i];
                if(c > 0 && dis[v] == dis[now] + 1)
                {
                    F x = dfs(v, min(flow - res, c));
                    res += x;
                    e[i].cap -= x;
                    e[i ^ 1].cap += x;
                }
                if(res == flow) break;
            }
            return res;
        };
        
        F ans = 0;
        while(bfs())
        {
            cur.assign(n, 0);
            ans += dfs(src, F_MAX);
        }
        return ans;
    }
};

int sex[maxn+5],v[maxn+5];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, g; cin >> n >> m >> g;
    vi sex(n), v(n);
    for(auto &x: sex) cin >> x;
    for(auto &x: v) cin >> x;

    int N = n + m;
    int src = N++, sink = N++;
    Dinic<int, inf> di(N);

    rep(i, 0, n - 1) di.add(src, i, sex[i] == 1 ? v[i] : 0);
    rep(i, 0, n - 1) di.add(i, sink, sex[i] == 1 ? 0 : v[i]);
    int ans = 0;
    rep(i, 0, m - 1)
    {
        int now = n + i;
        int sex_need, pay, k; cin >> sex_need >> pay >> k;
        ans += pay;
        while(k--)
        {
            int x; cin >> x; x--;
            if(sex_need == 0) di.add(x, now, inf);
            else di.add(now, x, inf);
        }
        int fri; cin >> fri;
        if(sex_need == 0) di.add(now, sink, pay + fri * g);
        else di.add(src, now, pay + fri * g);
    }
    ans -= di.work(src, sink);
    printf("%d\n", ans);
    return 0;
}