#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 3e5 + 5;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(time(0));

int n, m, x, y, cnt = 0;
LL ans = 0;
int pr[19][N], in[N], out[N], down[N], up[N], cross[N];
vector<int> g[N];
struct dat {
    int x, y, subx, suby;
};
vector<dat> info[N];

void dfs(int x, int fa) {
    pr[0][x] = fa;
    in[x] = ++cnt;
    for (auto u : g[x])
        if (u != fa)
            dfs(u, x);
    out[x] = ++cnt;
}

inline bool is_ancestor(int x, int y) { return in[x] <= in[y] && out[x] >= out[y]; }
inline int lca_son(int x, int y) {
    rrep(i, log2(n), 0) if (!is_ancestor(pr[i][x], y)) x = pr[i][x];
    return x;
}

void dfs2(int x, int fa) {
    cross[x] = up[x];
    for (auto u : g[x])
        if (u != fa)
            dfs2(u, x), cross[x] += cross[u];
    for (dat ele : info[x])
        ans += cross[x] - cross[ele.subx] - cross[ele.suby];
    cross[x] -= down[x];
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n - 1) {
        scanf("%d%d", &x, &y);
        g[x].PB(y), g[y].PB(x);
    }
    dfs(1, 0);
    pr[0][1] = 1;
    rep(i, 1, 18) rep(j, 1, n) pr[i][j] = pr[i - 1][pr[i - 1][j]];

    scanf("%d", &m);
    rep(i, 1, m) {
        scanf("%d%d", &x, &y);
        int subx = 0, suby = 0;
        if (!is_ancestor(x, y))
            subx = lca_son(x, y);
        if (!is_ancestor(y, x))
            suby = lca_son(y, x);
        int z = is_ancestor(x, y) ? x : pr[0][subx];
        if (subx > suby)
            swap(x, y), swap(subx, suby);
        info[z].PB({x, y, subx, suby});
    }

    //case 1: same root pairs
    rep(i, 1, n) {
        unordered_map<int, int> repeat;
        unordered_map<LL, int> repeat2;
        for (dat ele : info[i]) {
            int x = ele.x, y = ele.y, subx = ele.subx, suby = ele.suby;
            if (subx)
                repeat[subx]++;
            if (suby)
                repeat[suby]++;
            if (subx && suby)
                repeat2[1ll * subx * n + suby]++;
        }
        int sz = info[i].size();
        ans += 1ll * sz * (sz - 1) / 2;
        for (auto ele : repeat)
            ans -= 1ll * ele.second * (ele.second - 1) / 2;
        for (auto ele : repeat2)
            ans += 1ll * ele.second * (ele.second - 1) / 2;
    }

    //case 2: different root pairs
    rep(i, 1, n) for (dat ele : info[i]) {
        int x = ele.x, y = ele.y, subx = ele.subx, suby = ele.suby;
        if (subx)
            down[subx]++, up[x]++;
        if (suby)
            down[suby]++, up[y]++;
    }
    cross[0] = 0;
    dfs2(1, 0);
    cout << ans << endl;
    return 0;
}