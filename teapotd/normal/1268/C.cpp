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

struct Fenwick {
    using T = ll;
    static const T ID = 0;
    T f(T a, T b)  { return a+b; }

    vector<T> s;
    Fenwick(int n = 0) : s(n, ID) {}

    void modify(int i, T v) {
        for (; i < sz(s); i |= i+1) s[i]=f(s[i],v);
    }

    T query(int i) {
        T v = ID;
        for (; i > 0; i &= i-1) v = f(v, s[i-1]);
        return v;
    }

    T query(int i, int j) {
        return query(j) - query(i);
    }

    int lowerBound(T val) {
        if (val <= ID) return 0;
        int i = -1, mask = 1;
        while (mask <= sz(s)) mask *= 2;
        T off = ID;

        while (mask /= 2) {
            int k = mask+i;
            if (k < sz(s)) {
                T x = f(off, s[k]);
                if (val > x) i=k, off=x;
            }
        }
        return i+2;
    }
};

void run() {
    int n; cin >> n;
    Vi perm(n);

    each(e, perm) {
        cin >> e;
        e--;
    }

    Vi pos(n);
    rep(i, 0, n) pos[perm[i]] = i;

    Fenwick cnt(n), prefs(n);
    ll invs = 0;

    rep(i, 0, n) {
        invs += cnt.query(pos[i], n);
        cnt.modify(pos[i], 1);
        prefs.modify(pos[i], pos[i]);

        int median = (i+1) / 2;
        int medianPos = cnt.lowerBound(median+1) - 1;

        ll ans = invs;
        ans += prefs.query(medianPos+1, n) - ll(i-median)*medianPos - ll(i-median)*(i-median+1)/2;
        ans += ll(median)*medianPos - prefs.query(medianPos) - ll(median)*(median+1)/2;

        cout << ans << ' ';
    }

    cout << endl;
}