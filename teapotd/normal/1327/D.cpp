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

vector<Vi> divs;

void solve() {
    int n; cin >> n;

    Vi perm(n);
    each(p, perm) {
        cin >> p;
        p--;
    }

    Vi col(n);
    each(c, col) {
        cin >> c;
        c--;
    }

    vector<bool> seen(n), kek;
    int ans = INT_MAX;

    vector<Vi> steps(n);
    Vi cycle;

    rep(i, 0, n) if (!seen[i]) {
        int j = i;
        cycle.clear();
        while (!seen[j]) {
            cycle.pb(col[j]);
            seen[j] = 1;
            j = perm[j];
        }

        int k = sz(cycle);
        deb(cycle);

        each(d, divs[k]) {
            kek.assign(k, 0);

            rep(j, 0, k) if (!kek[j]) {
                int x = j, wanted = cycle[j];
                bool ok = 1;

                while (!kek[x]) {
                    if (wanted != cycle[x]) ok = 0;
                    kek[x] = 1;
                    x = (x+d) % k;
                }

                if (ok) {
                    ans = min(ans, d);
                }
            }
        }
    }

    deb(ans);
    cout << ans << '\n';
}

void run() {
    divs.resize(2e5+5);

    rep(i, 1, sz(divs)) {
        for (int j = i; j < sz(divs); j += i) {
            divs[j].pb(i);
        }
    }

    int t; cin >> t;
    while (t--) solve();
}