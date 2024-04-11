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

ll dp[80][80]; // prefix, taken -> max score
bool take[80][80]; // should take

ll check(int k, const vector<Pii>& elems) {
    rep(i, 0, 80) rep(j, 0, 80) dp[i][j] = -1e12;
    dp[0][0] = 0;

    rep(pref, 1, sz(elems)+1) {
        auto e = elems[pref-1];
        rep(taken, 0, k+1) {
            dp[pref][taken] = dp[pref-1][taken] + k*e.y;
            take[pref][taken] = 0;

            if (taken > 0) {
                ll alt = dp[pref-1][taken-1] + e.x + (taken-1)*e.y;
                if (alt > dp[pref][taken]) {
                    dp[pref][taken] = alt;
                    take[pref][taken] = 1;
                }
            }

            if (dp[pref][taken] < 0) {
                dp[pref][taken] = -1e12;
            }
        }
    }

    return dp[sz(elems)][k];
}

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<Pii, int>> elems(n);
    rep(i, 0, n) elems[i].y = i;
    each(e, elems) cin >> e.x.x >> e.x.y;
    sort(all(elems), [](pair<Pii, int> l, pair<Pii, int> r) { return l.x.y < r.x.y; });

    vector<Pii> tmp;
    int bestI = -1;
    ll ans = -1;

    rep(i, 0, n) {
        tmp.clear();
        rep(j, 0, n) if (j != i) tmp.pb(elems[j].x);
        ll alt = check(k-1, tmp);
        alt += elems[i].x.x + elems[i].x.y * (k-1);
        if (alt > ans) {
            ans = alt;
            bestI = i;
        }
    }

    Vi ind;
    tmp.clear();
    rep(j, 0, n) if (j != bestI) tmp.pb(elems[j].x), ind.pb(elems[j].y);

    ll alt = check(k-1, tmp);
    alt += elems[bestI].x.x + elems[bestI].x.y * (k-1);
    assert(alt == ans);

    Vi toTake, toDel;
    int pref = sz(tmp), taken = k-1;

    while (pref > 0) {
        if (take[pref][taken]) {
            toTake.pb(ind[pref-1]);
            taken--;
        } else {
            toDel.pb(ind[pref-1]);
        }
        pref--;
    }

    reverse(all(toTake));
    reverse(all(toDel));

    Vi moves;
    each(t, toTake) moves.pb(t+1);
    each(t, toDel) {
        moves.pb(t+1);
        moves.pb(-t-1);
    }
    moves.pb(elems[bestI].y+1);

    cout << sz(moves) << '\n';
    each(e, moves) cout << e << ' ';
    cout << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}