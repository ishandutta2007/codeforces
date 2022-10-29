#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define ar2 array<int, 2>
#define PB push_back
typedef long long LL;
const LL INF = 1e14;
const LL P = 998244353;
const int N = 2e5 + 5;

int n, k, x, y;
int fa[N], val[N];
bool leaf[N];
vector<int> g[N];
set<ar2> bannum;

void dfs1(int x, int f) {
    for (auto u : g[x])
        if (u != f) {
            fa[u] = x, val[u] = val[x] + 1, leaf[x] = false;
            dfs1(u, x);
        }
}

void dfs2(int x, int f) {
    for (auto u : g[x])
        if (u != f && val[u] > 0) {
            if (leaf[u])
                bannum.erase({val[u], u});
            val[u] = val[x] + 1;
            if (leaf[u])
                bannum.insert({val[u], u});
            dfs2(u, x);
        }
}

inline LL calc(int n, int r, int blue) {
    int wb = n - r;
    int b = min(min(n - r, blue), n / 2);
    return 1ll * (n - r - b) * (r - b);
}

int main() {
    cin >> n >> k;
    rep(i, 1, n - 1) scanf("%d%d", &x, &y), g[x].PB(y), g[y].PB(x);

    memset(leaf, true, sizeof leaf);
    val[1] = 1;
    dfs1(1, 0);

    rep(i, 1, n) if (leaf[i]) bannum.insert({val[i], i});

    LL ans = calc(n, 0, n);
    int blue = n;
    rep(i, 1, k) {
        if (blue) {
            auto iter = bannum.end();
            iter--;
            ar2 ele = *iter;
            bannum.erase(iter);
            int num = ele[0], x = ele[1];
            blue -= num;
            ans = max(ans, calc(n, i, blue));

            val[x] = 0;
            while (x > 1 && val[fa[x]]) {
                x = fa[x], val[x] = 0;
                dfs2(x, fa[x]);
            }
        } else
            ans = max(ans, 1ll * (n - i) * i);
    }
    cout << ans << endl;
}