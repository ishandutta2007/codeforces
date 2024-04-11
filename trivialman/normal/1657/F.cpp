#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 4e5 + 5, M = N * 26;
const LL INF = (1ll << 62) - 1;
const double pi = acos(-1);
mt19937 rng(time(0));

int T, n, q, x, y;
char s[N], ans[N];
vector<int> g[N];
int in[N], out[N], fa[N], a[N];
int tot, tim, top, cnt;
int head[M];
struct Edge {
    int to, nxt;
} e[M * 3];
int Q[M], dfn[M], low[M], scc[M], indg[M];

void add(int x, int y) { e[++tot] = {y, head[x]}, head[x] = tot, indg[y]++; }

void tarjan(int x) {
    dfn[x] = low[x] = ++tim;
    Q[++top] = x;
    for (int i = head[x]; i; i = e[i].nxt) {
        int u = e[i].to;
        if (!dfn[u]) {
            tarjan(u);
            low[x] = min(low[x], low[u]);
        } else
            low[x] = min(low[x], dfn[u]);
    }

    if (low[x] == dfn[x]) {
        cnt++;
        while (Q[top] != x)
            scc[Q[top--]] = cnt;
        scc[Q[top--]] = cnt;
    }
}

void dfs(int x, int f) {
    fa[x] = f;
    in[x] = ++tot;
    for (auto u : g[x])
        if (u != f)
            dfs(u, x);
    out[x] = ++tot;
}
bool ancestor(int x, int y) { return in[x] <= in[y] && out[x] >= out[y]; }
inline int id(int x, char ch) {
    int res = x * 26 + ch - 'a' - 25;
    assert(1 <= res && res <= 26 * n);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    rep(i, 1, n - 1) cin >> x >> y, g[x].PB(y), g[y].PB(x);
    tot = 0, dfs(1, 0), tot = 0;
    while (q--) {
        cin >> x >> y >> (s + 1);
        int m = strlen(s + 1), l = 0, r = m + 1;
        while (!ancestor(x, y))
            a[++l] = x, x = fa[x];
        a[++l] = x;
        while (y != x)
            a[--r] = y, y = fa[y];
        assert(l + 1 == r);
        int last = 0;
        rep(i, 1, m) {
            char ch1 = s[i], ch2 = s[m + 1 - i];
            if (ch1 == ch2) {
                rep(ch, 'a', 'z') if (ch != ch1) add(id(a[i], ch), id(a[i], ch1));
            } else {
                rep(ch, 'a', 'z') if (ch != ch1 && ch != ch2) {
                    int id1 = id(a[i], ch), id2 = id(a[i], ch1), id3 = id(a[i], ch2);
                    add(id1, id2), add(id1, id3);
                }
                if (last) {
                    int id1 = id(a[last], s[last]), id2 = id(a[i], ch1), id3 = id(a[last], s[m + 1 - last]), id4 = id(a[i], ch2);
                    add(id1, id2), add(id3, id4), add(id2, id1), add(id4, id3);
                }
                last = i;
            }
        }
    }
    rep(i, 1, n * 26) add(0, i);
    tarjan(0);
    rep(i, 1, n) {
        int mi = M, cnt = 1;
        rep(ch, 'a', 'z') {
            int sc = scc[id(i, ch)];
            assert(sc > 0);
            if (sc < mi)
                mi = sc, cnt = 1, ans[i] = ch;
            else if (sc == mi)
                cnt++;
        }
        if (cnt > 1)
            return cout << "NO", 0;
    }
    ans[n + 1] = 0;
    cout << "YES\n";
    cout << (ans + 1);
    return 0;
}