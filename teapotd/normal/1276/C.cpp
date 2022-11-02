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

    map<ll, ll> cnt;

    rep(i, 0, n) {
        ll k; cin >> k;
        cnt[k]++;
    }

    vector<pair<ll, ll>> elems;
    each(e, cnt) elems.pb({e.y, e.x});
    sort(all(elems));

    ll mul = sz(elems), add = 0;
    ll j = 0;
    ll ansX = 0, ansY = 0;

    for (ll x = 1; x*x <= n; x++) {
        while (j < sz(elems) && elems[j].x <= x) {
            add += elems[j].x;
            mul--;
            j++;
        }

        ll can = mul*x + add;
        deb(x, mul, add, j, can, elems);

        for (ll y = x; x*y <= n; y++) {
            if (can >= x*y && x*y > ansX*ansY) {
                ansX = x;
                ansY = y;
            }
        }
    }

    vector<vector<ll>> rect(ansX, vector<ll>(ansY));
    ll pos = 0;
    reverse(all(elems));

    each(e, elems) {
        rep(i, 0, min(e.x, ansX)) {
            if (pos >= ansX*ansY) break;
            ll x = pos%ansX, y = pos/ansX;
            y = (x+y) % ansY;
            rect[x][y] = e.y;
            pos++;
        }
    }

    cout << ansX*ansY << '\n';
    cout << ansX << ' ' << ansY << '\n';
    each(vec, rect) {
        each(k, vec) cout << k << ' ';
        cout << '\n';
    }
}