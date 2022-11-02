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

Vi par;

int find(int i) {
    return par[i] == -1 ? i : par[i] = find(par[i]);
}

bool join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j) return 0;
    par[i] = j;
    return 1;
}

void run() {
    int n, m; cin >> n >> m;

    map<int, vector<Pii>> edges;

    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        edges[w].pb({u-1, v-1});
    }

    par.resize(n, -1);

    vector<Pii> tmp;
    int ans = 0;

    each(vec, edges) {
        tmp.clear();

        each(e, vec.second) {
            if (find(e.x) != find(e.y)) {
                tmp.pb(e);
            }
        }

        each(e, tmp) {
            ans += !join(e.x, e.y);
        }
    }

    cout << ans << endl;
}