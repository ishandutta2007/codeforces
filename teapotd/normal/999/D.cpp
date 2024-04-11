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
    int n, m; cin >> n >> m;
    Vi elems(n);
    each(e, elems) cin >> e;

    vector<Vi> pos(m);
    rep(i, 0, n) pos[elems[i]%m].pb(i);

    queue<int> overflow;
    int wanted = n/m;

    rep(i, 0, m) {
        if (sz(pos[i]) > wanted) {
            while (sz(pos[i]) > wanted) {
                overflow.push(pos[i].back());
                pos[i].pop_back();
            }
        } else if (sz(pos[i]) < wanted) {
            while (!overflow.empty() && sz(pos[i]) < wanted) {
                pos[i].pb(overflow.front());
                overflow.pop();
            }
        }
    }

    rep(i, 0, m) {
        while (sz(pos[i]) < wanted) {
            assert(!overflow.empty());
            pos[i].pb(overflow.front());
            overflow.pop();
        }
        assert(sz(pos[i]) == wanted);
    }

    assert(overflow.empty());

    ll ans = 0;

    rep(i, 0, m) {
        each(p, pos[i]) {
            int r = elems[p] % m;
            int d;
            if (r <= i) {
                d = i-r;
            } else {
                d = i-r+m;
            }
            ans += d;
            elems[p] += d;
        }
    }

    cout << ans << '\n';
    each(k, elems) cout << k << ' ';
    cout << '\n';
}