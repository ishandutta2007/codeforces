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
    Vi f(n);

    each(k, f) {
        cin >> k;
        k--;
    }

    vector<bool> seen(n);
    each(e, f) if (e != -1) seen[e] = 1;

    vector<Pii> paths;

    rep(i, 0, n) if (!seen[i]) {
        int j = i;
        while (f[j] != -1) j = f[j];
        paths.pb({i, j});
    }

    rep(i, 0, sz(paths)) {
        auto& a = paths[i];
        auto& b = paths[(i+1)%sz(paths)];
        f[a.y] = b.x;
    }

    each(k, f) cout << k+1 << ' ';
    cout << '\n';
}