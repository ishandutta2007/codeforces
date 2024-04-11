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

struct FAU {
    Vi G;
    FAU(int n = 0) : G(n, -1) {}
    int size(int i) { return -G[find(i)]; }
    int find(int i) {
        return G[i] < 0 ? i : G[i] = find(G[i]);
    }
    bool join(int i, int j) {
        i = find(i); j = find(j);
        if (i == j) return 0;
        if (G[i] > G[j]) swap(i, j);
        G[i] += G[j]; G[j] = i;
        return 1;
    }
};

void run() {
    int n, m; cin >> n >> m;
    vector<string> G(n);
    each(s, G) cin >> s;

    int emptyCols = 0, emptyRows = 0;

    rep(i, 0, n) {
        string tmp = G[i];
        tmp.erase(unique(all(tmp)), tmp.end());
        if (count(all(tmp), '#') > 1) {
            cout << -1 << endl;
            return;
        }
        if (tmp == ".") {
            emptyRows++;
        }
    }

    rep(i, 0, m) {
        string tmp;
        rep(j, 0, n) tmp.pb(G[j][i]);
        tmp.erase(unique(all(tmp)), tmp.end());
        if (count(all(tmp), '#') > 1) {
            cout << -1 << endl;
            return;
        }
        if (tmp == ".") {
            emptyCols++;
        }
    }

    if ((emptyCols > 0) != (emptyRows > 0)) {
        cout << -1 << endl;
        return;
    }

    FAU fau(n*m);
    int ans = 0;

    rep(i, 0, n) rep(j, 0, m) if (G[i][j] == '#') {
        ans++;
        if (i > 0 && G[i-1][j] == '#') {
            ans -= fau.join((i-1)*m+j, i*m+j);
        }
        if (j > 0 && G[i][j-1] == '#') {
            ans -= fau.join(i*m+j-1, i*m+j);
        }
    }

    cout << ans << '\n';
}