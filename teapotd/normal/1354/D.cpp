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
    static const T ID = 0;
    T f(T a, T b)  { return a+b; }

    vector<T> s;
    Fenwick(int n = 0) : s(n, ID) {}

    // A[i] = f(A[i], v); time: O(lg n)
    void modify(int i, T v) {
        for (; i < sz(s); i |= i+1) s[i]=f(s[i],v);
    }

    // Get f(A[0], .., A[i-1]); time: O(lg n)
    T query(int i) {
        T v = ID;
        for (; i > 0; i &= i-1) v = f(v, s[i-1]);
        return v;
    }

    // Find smallest i such that
    // f(A[0],...,A[i-1]) >= val; time: O(lg n)
    // Prefixes must have non-descreasing values.
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
    int n, q; cin >> n >> q;
    Fenwick tree(n);

    rep(i, 0, n) {
        int a; cin >> a;
        a--;
        tree.modify(a, 1);
    }

    rep(i, 0, q) {
        int k; cin >> k;
        if (k >= 1) {
            k--;
            tree.modify(k, 1);
        } else {
            k = -k;
            int j = tree.lowerBound(k);
            tree.modify(j-1, -1);
        }
    }

    rep(i, 0, n) {
        int k = tree.query(i+1) - tree.query(i);
        if (k > 0) {
            cout << i+1 << '\n';
            return;
        }
    }

    cout << 0 << endl;
}