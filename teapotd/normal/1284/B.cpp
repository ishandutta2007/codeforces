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
    vector<Pii> small, great;

    rep(j, 0, n) {
        int l; cin >> l;
        Vi seq(l);
        each(s, seq) cin >> s;

        int sm = seq[0], gr = seq[0];
        bool has = 0;

        rep(i, 1, l) {
            if (sm < seq[i]) {
                has = 1;
            }
            sm = min(sm, seq[i]);
            gr = max(gr, seq[i]);
        }

        small.pb({sm, has});
        great.pb({gr, has});
    }

    ll ans = 0;
    sort(all(small));

    Vi prefs = {0};
    each(e, small) prefs.pb(prefs.back() + e.y);

    each(e, great) {
        if (e.y) {
            ans += n;
        } else {
            auto it = lower_bound(all(small), mp(e.x, 0));
            int ind = int(it - small.begin());
            ans += ind;
            ans += prefs.back() - prefs[ind];
        }
    }

    cout << ans << endl;
}