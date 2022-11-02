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

Vi odd;

ll countInversions(Vi perm, int mx) {
    ll ret = 0, cont = 1;

    while (cont) {
        odd.assign(mx+1, 0);
        cont = 0;

        rep(i, 0, sz(perm)) {
            if (perm[i] % 2) odd[perm[i]]++;
            else ret += odd[perm[i]+1];
            cont += perm[i] /= 2;
        }
    }
    return ret;
}

void run() {
    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
        map<int, Vi> elems;

        rep(i, 0, n*m) {
            int a; cin >> a;
            elems[a].pb(i);
        }

        vector<Vi> seats(n, Vi(m, -1));
        int row = 0, col = 0;

        each(e, elems) {
            auto& vec = e.y;
            reverse(all(vec));
            while (!vec.empty()) {
                if (sz(vec) >= m-col) {
                    for (int i = m-1; i >= col; i--) {
                        seats[row][i] = vec.back();
                        vec.pop_back();
                    }
                    row++;
                    col = 0;
                } else {
                    int nc = col + sz(vec);
                    for (int i = col+sz(vec)-1; i >= col; i--) {
                        seats[row][i] = vec.back();
                        vec.pop_back();
                    }
                    col = nc;
                }
            }
        }

        ll ans = 0;

        each(vec, seats) {
            reverse(all(vec));
            ans += countInversions(vec, n*m+5);
        }

        cout << ans << '\n';
    }
}