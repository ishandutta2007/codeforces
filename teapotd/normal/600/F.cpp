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

int colorEdges(vector<Pii>& edges,
               int n, Vi& col) {
    int m = sz(edges), c[2] = {}, ans = 0;
    Vi deg[2];
    vector<vector<Pii>> has[2];
    col.assign(m, 0);
    rep(i, 0, 2) {
        deg[i].resize(n+1);
        has[i].resize(n+1, vector<Pii>(n+1));
    }

    function<void(int,int)> dfs =
        [&](int x, int p) {
            Pii i = has[p][x][c[!p]];
            if (has[!p][i.x][c[p]].y) dfs(i.x, !p);
            else has[!p][i.x][c[!p]] = {};
            has[p][x][c[p]] = i;
            has[!p][i.x][c[p]] = {x, i.y};
            if (i.y) col[i.y-1] = c[p]-1;
        };

    rep(i, 0, m) {
        int x[2] = {edges[i].x+1, edges[i].y+1};
        rep(d, 0, 2) {
            deg[d][x[d]]++;
            ans = max(ans, deg[d][x[d]]);
            for (c[d] = 1; has[d][x[d]][c[d]].y;)
                c[d]++;
        }
        if (c[0]-c[1]) dfs(x[1], 1);
        rep(d, 0, 2)
            has[d][x[d]][c[0]] = {x[!d], i+1};
        col[i] = c[0]-1;
    }
    return ans;
}

void run() {
    int a, b, m;
    cin >> a >> b >> m;

    vector<Pii> edges(m);
    each(e, edges) cin >> e.x >> e.y, e.x--, e.y--;

    Vi col;
    cout << colorEdges(edges, max(a, b), col) << '\n';
    each(c, col) cout << c+1 << ' ';
    cout << '\n';
}