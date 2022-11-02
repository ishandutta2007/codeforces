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

struct Elem {
    int w, h, i;
    bool operator<(const Elem& r) const {
        return mp(w, h) < mp(r.w, r.h);
    }
};

void run() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<Elem> elems;

        rep(i, 0, n) {
            int w, h; cin >> w >> h;
            elems.pb({w, h, i});
            elems.pb({h, w, i});
        }

        sort(all(elems));

        Vi ans(n, -1);
        int j = 0;
        Pii best = {2e9, -1};

        each(e, elems) {
            while (j < n && elems[j].w < e.w) {
                best = min(best, mp(elems[j].h, elems[j].i));
                j++;
            }

            if (best.x < e.h) {
                ans[e.i] = best.y+1;
            }
        }

        each(a, ans) {
            cout << a << ' ';
        }
        cout << '\n';
    }
}