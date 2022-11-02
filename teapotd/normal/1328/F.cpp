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
    int n, k; cin >> n >> k;
    Vi elems(n);
    each(e, elems) cin >> e;
    sort(all(elems));

    vector<Pii> comp;

    each(e, elems) {
        if (comp.empty() || comp.back().x != e) {
            comp.pb({e, 1});
        } else {
            comp.back().y++;
        }
    }

    ll costUp = 0, costDown = 0;
    int numUp = 0, numDown = 0;

    rep(i, 1, sz(comp)) {
        numUp += comp[i].y;
        costUp += ll(comp[i].x-comp[0].x) * comp[i].y;
    }

    ll ans = 1e18;
    deb(comp);

    rep(i, 0, sz(comp)) {
        if (comp[i].y >= k) {
            ans = 0;
            break;
        }

        ans = min(ans, costUp + costDown - numUp - numDown + k - comp[i].y);
        if (numUp+comp[i].y >= k) {
            ans = min(ans, costUp - numUp + k - comp[i].y);
        }
        if (numDown+comp[i].y >= k) {
            ans = min(ans, costDown - numDown + k - comp[i].y);
        }

        deb(comp[i].x, comp[i].y, numDown, costDown, numUp, costUp);

        if (i+1 < sz(comp)) {
            numDown += comp[i].y;
            costDown += numDown * ll(comp[i+1].x-comp[i].x);
            costUp -= numUp * ll(comp[i+1].x-comp[i].x);
            numUp -= comp[i+1].y;
        }
    }

    cout << ans << '\n';
}