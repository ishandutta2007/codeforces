#include "bits/stdc++.h"
#define rep(i, a, n) for (auto i = a; i <= (n); ++i)
#define revrep(i, a, n) for (auto i = n; i >= (a); --i)
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
template<class A> string to_string(A v) {
    bool first = 1;
    string res = "{";
    for (const auto &x: v) {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")"; }

void debug_out() { cerr << endl; }
template<class Head, class... Tail> void debug_out(Head H, Tail... T) {
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

const int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m; cin >> n >> m;
    vi ind(n);
    vvi g(n);
    rep(i, 1, m) {
        int x, y; cin >> x >> y;
        x--, y--;
        g[y].push_back(x);
        ind[x]++;
    }

    vi dis(n, inf); dis[n - 1] = 0;
    priority_queue<pii> pq; pq.push({0, n - 1});
    vi mark(n);
    
    while (sz(pq)) {
        auto [_, now] = pq.top(); pq.pop();
        if (mark[now]) continue;
        mark[now] = 1;
        for (auto v: g[now]) if (chmin(dis[v], dis[now] + 1 + (--ind[v]))) pq.push({-dis[v], v});
    }
    printf("%d\n", dis[0]);
    return 0;
}