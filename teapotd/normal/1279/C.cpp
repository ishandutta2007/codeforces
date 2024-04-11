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

    void modify(int i, T v) {
        for (; i < sz(s); i |= i+1) s[i]=f(s[i],v);
    }

    T query(int i) {
        T v = ID;
        for (; i > 0; i &= i-1) v = f(v, s[i-1]);
        return v;
    }
};

void run() {
    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
        Vi stk(n), ord(m);

        each(e, stk) {
            cin >> e;
            e--;
        }

        each(e, ord) {
            cin >> e;
            e--;
        }

        Vi pos(n);
        rep(i, 0, n) pos[stk[i]] = i;

        Fenwick tree(n);
        rep(i, 0, n) tree.modify(i, 1);

        int sortedLen = 0;
        ll ans = 0;

        each(e, ord) {
            if (pos[e] >= sortedLen) {
                ans += tree.query(pos[e]) * 2;
                sortedLen = pos[e]+1;
            }
            tree.modify(pos[e], -1);
            ans++;
        }

        cout << ans << '\n';
    }
}