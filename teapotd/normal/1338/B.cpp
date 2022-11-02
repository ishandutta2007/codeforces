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

vector<Vi> G;
Vi depth, par;

void dfs(int v, int p, int d) {
    par[v] = p;
    depth[v] = d;
    each(e, G[v]) if (e != p) {
        dfs(e, v, d+1);
    }
}

void run() {
    int n; cin >> n;
    G.resize(n);

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        G[a-1].pb(b-1);
        G[b-1].pb(a-1);
    }

    int root = -1;
    rep(i, 0, n) {
        if (sz(G[i]) >= 2) {
            root = i;
            break;
        }
    }

    assert(root != -1);
    depth.resize(n, -1);
    par.resize(n, -1);
    dfs(root, -1, 0);

    bool has[2] = {0};
    rep(i, 0, n) {
        if (sz(G[i]) == 1) {
            has[depth[i]%2] = 1;
        }
    }

    int minF = (has[0] && has[1] ? 3 : 1);
    int maxF = n-1;
    vector<bool> seen(n);

    rep(i, 0, n) {
        if (sz(G[i]) == 1) {
            if (seen[par[i]]) maxF--;
            seen[par[i]] = 1;
        }
    }

    cout << minF << ' ' << maxF << '\n';
}