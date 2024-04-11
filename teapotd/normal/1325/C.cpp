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

void run() {
    int n; cin >> n;
    vector<Pii> edges(n-1);
    each(e, edges) {
        cin >> e.x >> e.y;
        e.x--; e.y--;
    }

    int ans = -1;
    Vi perm(n-1, -1);

    auto dst = [&](int v, int e) {
        return edges[e].x == v ? edges[e].y : edges[e].x;
    };

    if (n == 2) {
        ans = 1;
        perm[0] = 0;
    } else {
        vector<Vi> G(n);

        rep(i, 0, sz(edges)) {
            auto& e = edges[i];
            G[e.x].pb(i), G[e.y].pb(i);
        }

        bool path = 1;
        each(d, G) if (sz(d) > 2) path = 0;

        if (path) {
            ans = n-1;
            iota(all(perm), 0);
        } else {
            ans = 2;

            Vi steps;
            int last = -1;

            rep(v, 0, sz(G)) {
                auto& d = G[v];
                if (sz(d) == 1) {
                    steps.pb(d[0]);
                    last = dst(v, d[0]);
                    break;
                }
            }

            assert(last != -1);

            while (true) {
                bool ok = 0;
                each(e, G[last]) {
                    if (steps.back() != e) {
                        steps.pb(e);
                        last = dst(last, e);
                        ok = 1;
                        break;
                    }
                }
                if (!ok) break;
            }

            assert(sz(steps) >= 2);
            perm[steps[0]] = 0;
            perm[steps.back()] = 1;
            rep(i, 1, sz(steps)-1) perm[steps[i]] = i+2;

            Vi unused;
            unused.pb(2);
            rep(i, sz(steps)-1, n-3) unused.pb(i+2);

            each(k, perm) {
                if (k == -1) {
                    assert(!unused.empty());
                    k = unused.back();
                    unused.pop_back();
                }
            }

            assert(unused.empty());
        }
    }

    deb(ans);
    each(i, perm) cout << i << '\n';
}