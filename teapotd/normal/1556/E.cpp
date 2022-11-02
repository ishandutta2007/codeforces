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

struct RMQ {
    using T = ll;
    T ID = INT64_MAX;
    T f(T a, T b)  { return min(a, b); }

    vector<vector<T>> s;

    RMQ(const vector<T>& vec = {}) {
        s = {vec};
        for (int h = 1; h <= sz(vec); h *= 2) {
            s.pb({});
            auto& prev = s[sz(s)-2];
            rep(i, 0, sz(vec)-h*2+1)
                s.back().pb(f(prev[i], prev[i+h]));
        }
    }

    T query(int b, int e) {
        if (b >= e) return ID;
        int k = 31 - __builtin_clz(e-b);
        return f(s[k][b], s[k][e - (1<<k)]);
    }
};

struct RMQ2 {
    using T = ll;
    T ID = INT64_MIN;
    T f(T a, T b)  { return max(a, b); }

    vector<vector<T>> s;

    RMQ2(const vector<T>& vec = {}) {
        s = {vec};
        for (int h = 1; h <= sz(vec); h *= 2) {
            s.pb({});
            auto& prev = s[sz(s)-2];
            rep(i, 0, sz(vec)-h*2+1)
                s.back().pb(f(prev[i], prev[i+h]));
        }
    }

    T query(int b, int e) {
        if (b >= e) return ID;
        int k = 31 - __builtin_clz(e-b);
        return f(s[k][b], s[k][e - (1<<k)]);
    }
};

void run() {
    int n, q; cin >> n >> q;
    Vi c(n);

    rep(i, 0, n) {
        int e; cin >> e;
        c[i] -= e;
    }

    rep(i, 0, n) {
        int e; cin >> e;
        c[i] += e;
    }

    vector<ll> pref = {0};
    each(e, c) pref.pb(pref.back() + e);

    RMQ tMin(pref);
    RMQ2 tMax(pref);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        if (pref[l] != pref[r] || tMin.query(l, r) < pref[l]) {
            cout << -1 << '\n';
        } else {
            cout << tMax.query(l, r)-pref[l] << '\n';
        }
    }
}