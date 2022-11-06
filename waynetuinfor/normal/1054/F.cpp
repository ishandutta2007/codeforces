#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int inf = 1e9 + 1;
int x[maxn], y[maxn];
int match[maxn];
bool ux[maxn], uy[maxn], vs[maxn + maxn], hv[maxn];
vector<int> kx[maxn], ky[maxn];
vector<int> g[maxn], r[maxn + maxn];
set<pair<int, int>> cx[maxn], cy[maxn];

pair<int, int> inter(tuple<int, int, int> sx, tuple<int, int, int> sy) {
    if (get<1>(sx) >= get<0>(sy) || get<2>(sx) <= get<0>(sy)) return make_pair(inf, inf);
    if (get<1>(sy) >= get<0>(sx) || get<2>(sy) <= get<0>(sx)) return make_pair(inf, inf);
    return make_pair(get<0>(sx), get<0>(sy));
}

bool dfs(int x) {
    ux[x] = true;
    for (const int &y : g[x]) {
        if (uy[y]) continue;
        uy[y] = true;
        if (match[y] == -1 || dfs(match[y])) {
            match[y] = x;
            return true;
        }
    }
    return false;
}

void dfs2(int x) {
    vs[x] = true;
    for (const int &u : r[x]) {
        if (vs[u]) continue;
        dfs2(u);
    }
}

int main() {
    int n; scanf("%d", &n);
    vector<int> vx, vy;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        vx.push_back(x[i]);
        vy.push_back(y[i]);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
    for (int i = 0; i < n; ++i) {
        x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
        y[i] = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
        kx[x[i]].push_back(i);
        ky[y[i]].push_back(i);
    }
    vector<tuple<int, int, int>> sx, sy;
    for (int i = 0; i < (int)vx.size(); ++i) {
        sort(kx[i].begin(), kx[i].end(), [&](int i, int j) { return y[i] < y[j]; });
        for (int j = 1; j < (int)kx[i].size(); ++j) 
            sx.emplace_back(i, y[kx[i][j - 1]], y[kx[i][j]]);
    }
    for (int i = 0; i < (int)vy.size(); ++i) {
        sort(ky[i].begin(), ky[i].end(), [&](int i, int j) { return x[i] < x[j]; });
        for (int j = 1; j < (int)ky[i].size(); ++j) 
            sy.emplace_back(i, x[ky[i][j - 1]], x[ky[i][j]]);
    }
    for (int i = 0; i < (int)sx.size(); ++i) {
        for (int j = 0; j < (int)sy.size(); ++j) {
            int x, y; tie(x, y) = inter(sx[i], sy[j]);
            if (x == inf) continue;
            g[i].push_back(j);
        }
    }
    memset(match, -1, sizeof(match));
    for (int i = 0; i < (int)sx.size(); ++i) {
        memset(uy, false, sizeof(uy));
        dfs(i);
    }
    for (int i = 0; i < (int)sy.size(); ++i) {
        if (~match[i]) hv[match[i]] = true;
    }
    for (int i = 0; i < (int)sx.size(); ++i) {
        for (const int &y : g[i]) {
            if (match[y] == i) r[y + sx.size()].push_back(i);
            else r[i].push_back(y + sx.size());
        }
    }
    for (int i = 0; i < (int)sx.size(); ++i) {
        if (hv[i]) continue;
        dfs2(i);
    }
    for (int i = 0; i < (int)sx.size(); ++i) {
        if (!vs[i]) {
            int x = get<0>(sx[i]);
            cx[x].insert(make_pair(get<1>(sx[i]), get<2>(sx[i])));
        }
    }
    for (int i = 0; i < (int)sy.size(); ++i) {
        if (vs[i + sx.size()]) {
            int y = get<0>(sy[i]);
            cy[y].insert(make_pair(get<1>(sy[i]), get<2>(sy[i])));
        }
    }
    vector<tuple<int, int, int>> ax, ay;
    for (int i = 0; i < (int)vx.size(); ++i) {
        for (int j = 0; j < (int)kx[i].size(); ) {
            int k = j + 1;
            while (k < (int)kx[i].size() &&
                   cx[i].count(make_pair(y[kx[i][k - 1]], y[kx[i][k]])) == 0) ++k;
            ax.emplace_back(i, y[kx[i][j]], y[kx[i][k - 1]]);
            j = k;
        }
    } 
    for (int i = 0; i < (int)vy.size(); ++i) {
        for (int j = 0; j < (int)ky[i].size(); ) {
            int k = j + 1;
            while (k < (int)ky[i].size() &&
                   cy[i].count(make_pair(x[ky[i][k - 1]], x[ky[i][k]])) == 0) ++k;
            ay.emplace_back(i, x[ky[i][j]], x[ky[i][k - 1]]);
            j = k;
        }
    } 
    printf("%d\n", (int)ay.size());
    for (int i = 0; i < (int)ay.size(); ++i) {
        int y, l, r; tie(y, l, r) = ay[i];
        printf("%d %d %d %d\n", vx[l], vy[y], vx[r], vy[y]);
    }
    printf("%d\n", (int)ax.size());
    for (int i = 0; i < (int)ax.size(); ++i) {
        int x, l, r; tie(x, l, r) = ax[i];
        printf("%d %d %d %d\n", vx[x], vy[l], vx[x], vy[r]);
    }
    return 0;
}