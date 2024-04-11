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
    vector<Vi> elems(n, Vi(m));
    each(vec, elems) each(e, vec) cin >> e;

    int begin = 0, end = 1e9+5;
    int oneRow = 0;
    vector<bool> seen;
    Vi kek;

    while (begin+1 < end) {
        int mid = (begin+end) / 2;
        seen.assign(1<<m, 0);
        kek.assign(1<<m, -1);

        rep(j, 0, n) {
            auto& vec = elems[j];
            int mask = 0;
            rep(i, 0, m) {
                if (vec[i] >= mid) {
                    mask |= 1 << i;
                }
            }
            mask ^= (1<<m)-1;
            seen[mask] = 1;
            kek[mask] = j;
        }

        rep(mask, 1, 1<<m) {
            rep(b, 0, m) if ((mask >> b) & 1) {
                seen[mask] = seen[mask] || seen[mask^(1<<b)];
            }
        }

        bool ok = 0;
        rep(mask, 0, 1<<m) {
            if (kek[mask] != -1 && seen[mask ^ ((1<<m)-1)]) {
                ok = 1;
                oneRow = kek[mask];
                break;
            }
        }

        if (ok) {
            begin = mid;
        } else {
            end = mid;
        }
    }

    deb(begin);

    rep(i, 0, n) {
        int res = 1e9+5;
        rep(j, 0, m) {
            res = min(res, max(elems[i][j], elems[oneRow][j]));
        }

        if (res == begin) {
            cout << i+1 << ' ' << oneRow+1 << endl;
            return;
        }
    }

    assert(0);
}