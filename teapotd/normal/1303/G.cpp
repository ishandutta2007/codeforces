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
    cout << fixed << setprecision(18);
    run();
    return 0;
}

constexpr ll INF = 2e18;

// MAX of linear functions online; space: O(n)
struct Hull {
    static bool modeQ; // Toggles operator< mode

    struct Line {
        mutable ll a, b, end;

        ll intersect(const Line& r) const {
            if (a==r.a) return b > r.b ? INF : -INF;
            ll u = b-r.b, d = r.a-a;
            return u/d + ((u^d) >= 0 || !(u%d));
        }
        
        bool operator<(const Line& r) const {
            return modeQ ? end < r.end : a < r.a;
        }
    };

    multiset<Line> S;
    Hull() { S.insert({ 0, -INF, INF }); }

    // Updates segment end
    bool update(multiset<Line>::iterator it) {
        auto cur = it++; cur->end = INF;
        if (it == S.end()) return false;
        cur->end = cur->intersect(*it);
        return cur->end >= it->end;
    }

    // Insert f(x) = ax+b; time: O(lg n)
    void insert(ll a, ll b) {
        auto it = S.insert({ a, b, INF });
        while (update(it)) it = --S.erase(++it);
        rep(i, 0, 2)
            while (it != S.begin() && update(--it))
                update(it = --S.erase(++it));
    }

    // Query max(f(x) for each f): time: O(lg n)
    ll query(ll x) {
        modeQ = 1;
        auto l = *S.upper_bound({ 0, 0, x });
        modeQ = 0;
        return l.a*x + l.b;
    }
};

bool Hull::modeQ = false;

struct Path {
    ll sum, len, up, down;
    DBP(sum, len, up, down);
};

vector<Vi> G;
vector<ll> vals;
vector<bool> block;
Vi siz;
vector<vector<Path>> paths;
ll ans = 0;

void dfs(int v, int p) {
    siz[v] = 1;
    each(e, G[v]) if (e != p && !block[e]) {
        dfs(e, v);
        siz[v] += siz[e];
    }
}

void collect(int v, int p, ll sum, ll len, ll up, ll down) {
    bool leaf = 1;

    sum += vals[v];
    len++;
    up += len*vals[v];
    down += sum;

    each(e, G[v]) if (e != p && !block[e]) {
        leaf = 0;
        collect(e, v, sum, len, up, down);
    }

    if (leaf) {
        paths.back().pb({ sum, len, up, down });
    }
}

void check(ll r) {
    Hull hull;
    hull.insert(0, 0);

    each(vec, paths) {
        each(p, vec) {
            ans = max(ans, hull.query(p.sum + r) + p.up + p.sum + r);
        }
        each(p, vec) {
            hull.insert(p.len, p.down);
        }
    }

    ans = max(ans, hull.query(r) + r);
}

void solve(int v) {
    dfs(v, -1);
    int p = -1, s = siz[v];
    bool ok = 1;
    while (ok) {
        ok = 0;
        each(e, G[v]) {
            if (e != p && !block[e] && siz[e] > s/2) {
                p = v; v = e; ok = 1;
                break;
            }
        }
    }

    paths.clear();
    each(e, G[v]) if (!block[e]) {
        paths.emplace_back();
        collect(e, v, 0, 0, 0, 0);
    }

    check(vals[v]);
    reverse(all(paths));
    check(vals[v]);

    block[v] = 1;
    each(e, G[v]) if (!block[e]) solve(e);
}

void run() {
    int n; cin >> n;
    G.resize(n);

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    vals.resize(n);
    each(a, vals) cin >> a;

    block.resize(n);
    siz.resize(n);
    solve(0);
    cout << ans << endl;
}