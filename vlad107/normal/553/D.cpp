#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <stdio.h>

#define pb push_back
#define mp make_pair

using namespace std;

const int N = 1e5 + 100;

struct State {
    int nom, x, y;
    State() {}
    State(int nom, int x, int y) : nom(nom), x(x), y(y) {}

    bool operator < (const State & u) const {
        return (x * 1LL * u.y < u.x * 1LL * y) || 
        ((x * 1LL * u.y == u.x * 1LL * y) && (nom < u.nom));
    }

    // bool operator ==(const State &u) const {
    //  return ((nom == u.nom) && (x == u.x) && (y == u.y));
    // }
};

int n, m, k, a[N], d[N];
vector<int> g[N];

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        --x;
        a[x] = 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    set<State> s;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) continue;
        d[i] = 0;
        for (int j : g[i]) d[i] += 1 - a[j];
        // cerr << i << " " << d[i] << " " << g[i].size() << endl;
        s.insert(State(i, d[i], g[i].size()));
    }
    State u(-1, 0, 1);
    vector<int> vv;
    while (!s.empty()) {
        State cur = *s.begin();
        s.erase(s.begin());
        if (u < cur) u = cur;
        int x = cur.nom;
        vv.pb(x);
        for (int y : g[x]) {
            if (!a[y]) {
                // cerr << y << " " << d[y] << " " << g[y].size() << endl;
                s.erase(s.find(State(y, d[y], g[y].size())));
                // cerr << "done\n" << endl;
                --d[y];
                s.insert(State(y, d[y], g[y].size()));
            }
        }
        a[x] = 1;
    }
    vector<int> ans;
    for (int i = (int)vv.size() - 1; i >= 0; i--) {
        ans.push_back(vv[i]);
        if (vv[i] == u.nom) break;
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) printf("%d ", 1 + ans[i]);
    puts("");
}