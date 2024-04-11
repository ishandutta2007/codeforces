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

struct Player {
    int aud;
    int play[7];
};

void run() {
    int n, p, k; cin >> n >> p >> k;

    vector<Player> elems(n);
    each(e, elems) cin >> e.aud;
    each(e, elems) {
        rep(i, 0, p) cin >> e.play[i];
    }

    sort(all(elems), [](const Player& l, const Player& r) {
        return l.aud > r.aud;
    });

    vector<ll> prev, cur(1<<p, -1e16);
    cur[0] = 0;

    rep(i, 0, n) {
        prev = cur;

        rep(mask, 0, 1<<p) {
            int bits = __builtin_popcount(mask);
            if (i < k+bits) {
                cur[mask] += elems[i].aud;
            }
        }

        rep(mask, 0, 1<<p) {
            rep(bit, 0, p) if (!((mask >> bit) & 1)) {
                int kek = mask | (1 << bit);
                cur[kek] = max(cur[kek], prev[mask] + elems[i].play[bit]);
            }
        }
    }

    ll ans = cur.back();
    cout << ans << '\n';
}