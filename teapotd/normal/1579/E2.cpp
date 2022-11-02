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

struct Fenwick {
    using T = int;
    T ID = 0;
    T f(T a, T b) { return a+b; }

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

Vi compressVec(vector<int*>& vec) {
    sort(all(vec),
        [](int* l, int* r) { return *l < *r; });
    Vi old;
    each(e, vec) {
        if (old.empty() || old.back() != *e)
            old.pb(*e);
        *e = sz(old)-1;
    }
    return old;
}

void run() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        Vi elems(n);
        each(e, elems) cin >> e;

        vector<int*> tmp;
        each(e, elems) tmp.pb(&e);
        compressVec(tmp);

        Fenwick tree(n+5);
        ll ans = 0;
        deb(elems);

        rep(i, 0, n) {
            int inv = i - tree.query(elems[i]+1);
            int inv2 = tree.query(elems[i]);
            ans += min(inv, inv2);
            tree.modify(elems[i], 1);
        }

        cout << ans << '\n';
    }
}