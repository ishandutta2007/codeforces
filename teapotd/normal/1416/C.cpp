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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

void run() {
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;

    int ans = 0;
    ll tot = 0;
    ll cont = 1;
    gp_hash_table<int, int> odd[2];

    for (int bit = 0; cont; bit++) {
        odd[0].clear();
        odd[1].clear();
        cont = 0;
        ll inv[2] = {0, 0};

        rep(i, 0, sz(elems)) {
            int e = elems[i];
            int p = elems[i] % 2;
            odd[p][e/2]++;
            inv[p] += odd[!p][e/2];
            cont += elems[i] /= 2;
        }

        if (inv[1] < inv[0]) {
            ans |= 1 << bit;
            tot += inv[1];
        } else {
            tot += inv[0];
        }
    }

    cout << tot << ' ' << ans << ' ' << '\n';
}