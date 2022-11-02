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

void run() {
    int n, k; cin >> n >> k;
    Vi skill(n);
    each(s, skill) cin >> s;

    vector<Vi> G(n);

    rep(i, 0, k) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    vector<Pii> sorted;
    rep(i, 0, n) sorted.pb({skill[i], i});
    sort(all(sorted));

    int sm = 0, eq = 0;
    Vi ans(n);

    rep(i, 0, n) {
        Pii p = sorted[i];

        if (i > 0 && sorted[i-1].x == p.x) {
            eq++;
        } else {
            sm += eq;
            eq = 1;
        }

        ans[p.y] = sm;

        each(e, G[p.y]) {
            if (skill[e] < p.x) {
                ans[p.y]--;
            }
        }
    }

    each(e, ans) cout << e << ' ';
    cout << '\n';
}