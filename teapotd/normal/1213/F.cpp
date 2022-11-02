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

struct SCC : Vi {
    vector<Vi> comps;
    Vi S;
    SCC() {}
    SCC(vector<Vi>& G) : Vi(sz(G),-1), S(sz(G)) {
        rep(i, 0, sz(G)) if (!S[i]) dfs(G, i);
    }
    int dfs(vector<Vi>& G, int v) {
        int low = S[v] = sz(S);
        S.pb(v);
        each(e, G[v]) if (at(e) < 0)
            low = min(low, S[e] ?: dfs(G, e));
        if (low == S[v]) {
            comps.pb({});
            rep(i, S[v], sz(S)) {
                at(S[i]) = sz(comps)-1;
                comps.back().pb(S[i]);
            }
            S.resize(S[v]);
        }
        return low;
    }
};

void run() {
    int n, k; cin >> n >> k;
    vector<Vi> G(n);

    rep(t, 0, 2) {
        int last; cin >> last;
        rep(i, 1, n) {
            int cur; cin >> cur;
            G[last-1].pb(cur-1);
            last = cur;
        }
    }

    SCC scc(G);
    
    if (sz(scc.comps) < k) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    rep(i, 0, n) {
        int j = min(scc[i], k-1);
        cout << char('z'-j);
    }
    cout << endl;
}