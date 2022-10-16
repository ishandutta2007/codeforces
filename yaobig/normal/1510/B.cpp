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

template<class F, F F_MAX, class C, C C_MAX> struct MinCostFlow
{   // 0-based indexing.
    int n;
    struct E { int v; F cap; C w; };
    vector<E> e;
    vector<vi> g;
    vector<C> h;
    MinCostFlow(int n): n(n), g(n), h(n) {}
    void add(int u, int v, F c, C w)
    {
        g[u].pb(sz(e)); e.pb({v, c, w});
        g[v].pb(sz(e)); e.pb({u, 0, -w});
    }
    pair<C, F> work(int src, int sink, F mx_flow = F_MAX)
    {   
        C cost = 0; F flow = 0;
        while(mx_flow)
        {   // use "static" to accelerate
            priority_queue<pair<C, int> > q;
            vector<C> dis(n, C_MAX);
            dis[src] = 0; q.push({0, src});
            
            vi pre(n, -1), mark(n, 0);
            while(sz(q))
            {
                auto [d, now] = q.top(); q.pop();
                // Using mark[] is safer than compare -d and dis[now] when the cost is float type.
                if(mark[now]) continue;
                mark[now] = 1;
                for(auto i: g[now])
                {
                    auto [v, c, w] = e[i];
                    if(c > 0 && chmin(dis[v], dis[now] + w + h[now] - h[v]))
                    {
                        q.push({-dis[v], v});
                        pre[v] = i;
                    }
                }
            }
            if(pre[sink] == -1) break;
            
            rep(i, 0, n - 1) h[i] += dis[i];
            F aug = mx_flow;
            for(int i = pre[sink]; ~i; i = pre[e[i ^ 1].v]) chmin(aug, e[i].cap);
            for(int i = pre[sink]; ~i; i = pre[e[i ^ 1].v]) e[i].cap -= aug, e[i ^ 1].cap += aug;
            mx_flow -= aug;
            flow += aug;
            cost += aug * h[sink];
        }
        return {cost, flow};
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int d, k; cin >> d >> k;
    int n = 1 << d;
    vi cnt(n);
    rep(i, 0, k - 1)
    {
        string s; cin >> s; 
        int msk = 0;
        rep(i, 0, d - 1) if(s[i] == '1') msk |= 1 << i;
        cnt[msk]++;
    }
    int N = 2 * n;
    int src = N++, sink = N++;
    MinCostFlow<int, inf, int, inf> mcf(N);
    rep(i, 0, n - 1) mcf.add(i, i + n, n, 1);
    rep(i, 0, n - 1) mcf.add(i + n, 0, 1, 0); // reset.
    rep(msk, 0, n - 1)
    {
        rep(i, 0, d - 1) if((msk >> i & 1) == 0)
        {
            int nmsk = msk | (1 << i);
            mcf.add(msk + n, nmsk, n, 0);
        }
    }
    rep(msk, 0, n - 1) if(cnt[msk])
    {
        mcf.add(src, msk + n, 1, 0);
        mcf.add(msk, sink, 1, 0);
    }
    auto [cost, flow] = mcf.work(src, sink);
    printf("%d\n", cost + k - 1);
    
    vvi e(n);
    int tot = 0;
    rep(u, 0, N - 1) for(auto i: mcf.g[u])
    {
        auto [v, c, w] = mcf.e[i];
        if(u < n && v >= n && v < n * 2) // want back edge.
        {
            v -= n;
            if(v != u)
            {
                while(c--) e[v].pb(u), tot++;
            }
        }
    }
    int now = 0;
    while(1)
    {
        assert(sz(e[now]) != 0);
        int v = e[now].back(); e[now].pop_back(); tot--;
        if(v != 0) printf("%d ", __builtin_ctz(now ^ v)), now = v;
        else 
        {
            if(tot == 0) break;
            else printf("R "), now = 0;
        }
    }
    puts("");
    return 0;
}