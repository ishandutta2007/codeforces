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
    Vi elems(n);
    each(e, elems) cin >> e;

    Vi pref(n, 1), suf(n, 1);
    int ans = 1;

    rep(i, 1, n) {
        if (elems[i-1] < elems[i]) {
            pref[i] = pref[i-1]+1;
            ans = max(ans, pref[i]);
        }
    }

    for (int i = n-2; i >= 0; i--) {
        if (elems[i] < elems[i+1]) {
            suf[i] = suf[i+1]+1;
        }
    }

    rep(i, 1, n-1) {
        if (elems[i-1] < elems[i+1]) {
            ans = max(ans, pref[i-1]+suf[i+1]);
        }
    }

    cout << ans << endl;
}