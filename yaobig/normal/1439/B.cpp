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


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int cas; cin >> cas; while (cas--) {
        int n, m, k; cin >> n >> m >> k;
        static vvi g; g.assign(n, {});
        rep(i, 1, m) {
            int x, y; cin >> x >> y;
            x--, y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for (auto &vec: g) sort(all(vec));

        auto solve = [&]() {
            if (1ll * k * (k - 1) > m * 2) return 0;

            vi deg(n), alive(n, 1);
            set<pii> S;
            rep(i, 0, n - 1) {
                deg[i] = sz(g[i]);
                S.insert({deg[i], i});
            }
            while (sz(S)) {
                auto [_, now] = *S.begin();
                if (deg[now] >= k) {
                    printf("%d %d\n", 1, sz(S));
                    for (auto [_, x]: S) printf("%d ", x + 1);
                    puts("");
                    return 1;
                } else if (deg[now] == k - 1) {
                    vi vec;
                    for (auto v: g[now]) if (alive[v]) vec.push_back(v);
                    assert(sz(vec) == k - 1);
                    int ok = 1;
                    rep(i, 0, sz(vec) - 1) if (ok) rep(j, i + 1, sz(vec) - 1) {
                        int u = vec[i], v = vec[j];
                        auto it = lower_bound(all(g[u]), v);
                        if (it == g[u].end() || *it != v) { ok = 0; break; }
                    }
                    if (ok) {
                        puts("2"); vec.push_back(now);
                        for (auto x: vec) printf("%d ", x + 1);
                        puts("");
                        return 1;
                    }
                }
                S.erase(S.begin());
                alive[now] = 0;
                for (auto v: g[now]) if (alive[v]) S.erase({deg[v], v}), S.insert({--deg[v], v});
            }
            return 0;
        };
        if (solve() == 0) puts("-1");
    }
    return 0;
}