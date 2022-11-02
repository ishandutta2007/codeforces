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

void solve() {
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;

    int sm = INT_MAX;
    int smInd = -1;

    rep(i, 0, n) {
        int e = elems[i]-i;

        if (e > sm) {
            cout << "YES\n";
            cout << smInd+1 << ' ' << i+1 << '\n';
            return;
        }

        if (e < sm) {
            sm = e;
            smInd = i;
        }
    }

    sm = INT_MAX;
    smInd = -1;

    for (int i = n-1; i >= 0; i--) {
        int e = elems[i]+i;

        if (e > sm) {
            cout << "YES\n";
            cout << i+1 << ' ' << smInd+1 << '\n';
            return;
        }

        if (e < sm) {
            sm = e;
            smInd = i;
        }
    }

    cout << "NO\n";
}

void run() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}