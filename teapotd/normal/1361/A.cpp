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
    int n, m; cin >> n >> m;
    vector<Vi> G(n);

    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    vector<Pii> blogs; // topic, blog
    Vi kek(n);

    rep(i, 0, n) {
        int k; cin >> k;
        blogs.pb({k, i});
        kek[i] = k;
    }

    sort(all(blogs));
    Vi used(n+1, -1);

    rep(i, 0, n) {
        each(e, G[i]) used[kek[e]] = i;

        bool ok = (used[kek[i]] != i);
        rep(j, 1, kek[i]) if (used[j] != i) ok = 0;

        if (!ok) {
            cout << -1 << '\n';
            return;
        }
    }

    each(b, blogs) {
        cout << b.y+1 << ' ';
    }
    cout << '\n';
}