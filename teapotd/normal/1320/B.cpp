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
        G[v].pb(u);
    }

    int k; cin >> k;
    Vi path(k);
    each(v, path) {
        cin >> v;
        v--;
    }

    Vi dist(n, -1);
    queue<int> que;

    que.push(path.back());
    dist[path.back()] = 0;

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        each(e, G[v]) {
            if (dist[e] == -1) {
                dist[e] = dist[v]+1;
                que.push(e);
            }
        }
    }

    Vi numNext(n);

    rep(v, 0, sz(G)) each(e, G[v]) {
        if (dist[v]+1 == dist[e]) {
            numNext[e]++;
        }
    }

    int ansMin = 0, ansMax = 0;

    rep(i, 1, sz(path)) {
        int v = path[i-1], w = path[i];

        if (dist[v] != dist[w]+1) {
            ansMin++;
            ansMax++;
        } else if (numNext[v] > 1) {
            ansMax++;
        }
    }

    cout << ansMin << ' ' << ansMax << '\n';
}