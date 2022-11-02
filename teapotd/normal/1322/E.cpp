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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

void run() {
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;

    Vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int l, int r) { return elems[l] < elems[r]; });

    set<int> zeroes, par[2];
    vector<bool> cur(n);
    vector<int> ans(n, -1);
    int rounds = 0;

    par[0].insert(-1);
    par[1].insert(-1);
    par[0].insert(n);
    par[1].insert(n);

    rep(i, 0, n) {
        zeroes.insert(i);
        par[i%2].insert(i);
    }

    auto del = [&](int b, int e, int v) {
        for (auto it = zeroes.lower_bound(b); it != zeroes.end() && *it < e; it = zeroes.erase(it)) {
            ans[*it] = v;
        }
    };

    auto upd = [&](int p, int elem) {
        if (p < 0 || p >= n) return;
        deb(p, elem, cur, ans, par);

        auto nxt = par[(p%2)^cur[p]^1].lower_bound(p);
        int b = *prev(nxt)+1, e = *nxt-1;
        rounds = max(rounds, (e-b) / 2);

        if (cur[p]) {
            if (b == p) del(p-1, p, elem);
            if (e == p) del(p, p+1, elem);
        }
        deb(b, e);

        if (cur[b] == cur[e]) {
            if (cur[b] == 1) {
                del(b, e+1, elem);
            }
        } else {
            int m = (b+e+1) / 2;
            if (cur[b] == 1) {
                del(b, m, elem);
            } else {
                del(m, e, elem);
            }
        }
    };

    for (int j, i = 0; i < n; i = j) {
        j = i+1;
        while (j < n && elems[ord[i]] == elems[ord[j]]) j++;

        deb(cur, ans);

        rep(k, i, j) {
            int p = ord[k];
            assert(!cur[p]);
            cur[p] = 1;
            par[p%2].erase(p);
            par[(p+1)%2].insert(p);
        }

        deb(cur);

        rep(k, i, j) {
            int p = ord[k];
            assert(cur[p]);
            upd(p, elems[p]);
            upd(p-1, elems[p]);
            upd(p+1, elems[p]);
        }
    }

    cout << rounds << '\n';
    each(a, ans) cout << a << ' ';
    cout << '\n';
}