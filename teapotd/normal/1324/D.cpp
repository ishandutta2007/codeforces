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
    int n; cin >> n;
    vector<Pii> elems(n);
    rep(i, 0, n) cin >> elems[i].x;
    rep(i, 0, n) cin >> elems[i].y;

    Vi A, B;
    each(e, elems) {
        A.pb(e.x - e.y);
        B.pb(e.y - e.x);
    }

    sort(all(A));
    sort(all(B));

    ll ans = 0;
    int j = 0;

    rep(i, 0, n) {
        while (j < n && B[j] < A[i]) j++;
        ans += j;
        ans -= A[i] > 0;
    }

    ans /= 2;
    cout << ans << '\n';
}