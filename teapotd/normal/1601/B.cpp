#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

// 1, ..., len-1 = internal vertices
// len, ..., len+n = tree leaves corresponding to 0, ..., n
// len*2+1, ..., len*2+n = well vertices corresponding to 1, ..., n
// len*2+n = src, len = dst
vector<vector<Pii>> G;
int len;

void add(int vb, int ve, int from, int i = 1, int b = 0, int e = len) {
    if (vb >= e || b >= ve) return;
    if (b >= vb && e <= ve) {
        G[from].pb({i, 1});
        return;
    }
    int m = (b+e) / 2;
    add(vb, ve, from, i*2, b, m);
    add(vb, ve, from, i*2+1, m, e);
}

void run() {
    int n; cin >> n;
    Vi a(n), b(n);
    each(e, a) cin >> e;
    each(e, b) cin >> e;

    for (len = 1; len <= n; len *= 2);
    G.resize(len*2+n+1);

    rep(i, 1, len) {
        G[i].pb({i*2, 0});
        G[i].pb({i*2+1, 0});
    }

    rep(i, 1, n+1) {
        G[len+i].pb({len*2 + i + b[i-1], 0});
        add(i-a[i-1], i+1, len*2+i);
    }

    constexpr int inf = 1e9;
    Vi dist(sz(G), inf), prv(sz(G), -1);
    deque<int> que;
    dist[len*2+n] = 0;
    que.pb(len*2+n);

    while (!que.empty()) {
        int v = que.front();
        que.pop_front();
        each(e, G[v]) {
            int alt = dist[v] + e.y;
            if (alt < dist[e.x]) {
                dist[e.x] = alt;
                prv[e.x] = v;
                if (e.y == 0) {
                    que.push_front(e.x);
                } else {
                    que.pb(e.x);
                }
            }
        }
    }

    if (dist[len] == inf) {
        cout << "-1\n";
        return;
    }

    Vi ans;
    for (int v = len; v != -1; v = prv[v]) {
        if (v >= len && v <= len+n) {
            ans.pb(v-len);
        }
    }

    reverse(all(ans));
    cout << sz(ans) << '\n';
    each(e, ans) cout << e << ' ';
    cout << '\n';
}