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

struct Seg {
    ll from, n;
    ll begin, end;
    DBP(from, n, begin, end);

    ll get(ll i) {
        deb(i, begin, end);
        assert(i >= begin && i < end);
        i -= begin;

        if (from == n) {
            return 1;
        }

        if (i%2 == 0) {
            return from;
        }

        i /= 2;
        return from+i+1;
    }
};

Seg makeSeg(ll from, ll n, ll begin) {
    if (from == n) {
        return {n, n, begin, begin+1};
    }
    return {from, n, begin, begin + (n-from)*2};
}

void run() {
    int t; cin >> t;
    vector<Seg> segs;

    while (t--) {
        ll n, l, r;
        cin >> n >> l >> r;

        segs.clear();
        segs.pb(makeSeg(1, n, 1));
        rep(i, 2, n+1) {
            segs.pb(makeSeg(i, n, segs.back().end));
        }

        ll cur = 0;
        for (ll i = l; i <= r; i++) {
            while (i >= segs[cur].end) cur++;
            cout << segs[cur].get(i) << ' ';
        }
        cout << '\n';
        deb(0);
    }
}