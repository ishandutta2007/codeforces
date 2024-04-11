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

ll solve() {
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> elems(n);
    each(e, elems) cin >> e;

    each(e, elems) {
        if (e == x) {
            return 1;
        }
    }

    ll great = 0;
    each(e, elems) great = max(great, e);

    return max((x+great-1) / great, 2ll);
}

void run() {
    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}