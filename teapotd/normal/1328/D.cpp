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
    int q; cin >> q;

    while (q--) {
        int n; cin >> n;
        Vi elems(n);
        each(e, elems) cin >> e;

        Vi tmp = elems;
        tmp.erase(unique(all(tmp)), tmp.end());
        while (!tmp.empty() && tmp[0] == tmp.back()) tmp.pop_back();

        int k;
        Vi ans;

        if (tmp.empty()) {
            k = 1;
            ans.resize(n, 1);
        } else {
            int cur = 0;
            rep(i, 0, n) {
                if (i > 0 && elems[i-1] != elems[i]) {
                    cur ^= 1;
                }
                ans.pb(cur+1);
            }
            k = 2;
            if (sz(tmp) % 2 == 1 && elems[0] != elems.back()) {
                bool ok = 0;
                rep(i, 1, n) {
                    if (elems[i] == elems[i-1]) {
                        rep(j, i, n) ans[j] = (ans[j] == 1 ? 2 : 1);
                        ok = 1;
                        break;
                    }
                }
                if (!ok) {
                    k = 3;
                    rep(i, 0, n) {
                        if (elems[i] != elems[0]) break;
                        ans[i] = 3;
                    }
                    for (int i = n-1; i >= 0; i--) {
                        if (elems[i] != elems[0]) break;
                        ans[i] = 3;
                    }
                }
            }
        }

#ifdef LOC
        int gr = 0;
        rep(i, 0, n) {
            assert(ans[i] >= 1);
            gr = max(gr, ans[i]);
            if (elems[i] != elems[(i+1)%n]) {
                assert(ans[i] != ans[(i+1)%n]);
            }
        }
        assert(gr == k);
#endif

        cout << k << '\n';
        each(e, ans) cout << e << ' ';
        cout << '\n';
    }
}