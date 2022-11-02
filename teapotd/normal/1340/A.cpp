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

void solve() {
    int n; cin >> n;
    Vi perm(n);
    each(p, perm) {
        cin >> p;
        p--;
    }

    Vi pos(n);
    rep(i, 0, n) {
        pos[perm[i]] = i;
    }

    set<int> avail;
    set<Pii> opts;

    rep(i, 0, n) {
        avail.insert(i);
        opts.insert({ 1, i });
    }
    avail.insert(-1);

    deb(0);

    rep(e, 0, n) {
        auto it = avail.lower_bound(pos[e]);
        auto prv = prev(it);
        int score = *it - *prv;

        deb(e, score, avail, opts);

        if (score != opts.rbegin()->x) {
            cout << "No\n";
            return;
        }

        auto nxt = next(it);
        if (nxt != avail.end()) {
            int v = *nxt - *prv;
            int k = *nxt;
            opts.erase(opts.find(mp(*nxt - *it, k)));
            opts.insert({v, k});
        }

        opts.erase(opts.find(mp(score, pos[e])));
        avail.erase(it);
    }

    cout << "Yes\n";
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}