#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
const long long inf = 2e18 + 1;
vector<int> G[maxn];
int tin[maxn], top[maxn], sz[maxn], maxson[maxn], p[maxn], dep[maxn];
int t, vid[maxn], a[maxn], b[maxn];
long long c[maxn];

inline long long mul(long long a, long long b) {
    return log(a) + log(b) >= log(inf) ? inf : a * b;
}

void dfs(int now, int fa, int d) {
    p[now] = fa; dep[now] = d;
    sz[now] = 1; maxson[now] = 0;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d + 1);
        sz[now] += sz[u];
        if (sz[u] > sz[maxson[now]]) maxson[now] = u;
    }
}

void link(int now, int ltop) {
    top[now] = ltop;
    tin[now] = ++t;
    if (!maxson[now]) return;
    link(maxson[now], ltop);
    for (int u : G[now]) if (u != p[now]) {
        if (u == maxson[now]) continue;
        link(u, u);
    }
}

struct SegmentTree {
#define M ((L + R) >> 1)
    static SegmentTree mem[800000];
    static SegmentTree *ptr;
    SegmentTree *lc, *rc;
    long long val;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        val = 1ll;
        if (L == R) return;
        lc = new (ptr++) SegmentTree(L, M); rc = new (ptr++) SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        val = mul(lc->val, rc->val);
    }
    void modify(int L, int R, int p, long long v) {
        if (L == R) return val = v, void();
        if (p <= M) lc->modify(L, M, p, v);
        else rc->modify(M + 1, R, p, v);
        pull();
    }
    long long query(int L, int R, int l, int r) {
        if (l > r) return 1ll;
        if (L > r || l > R) return 1ll;
        if (L >= l && R <= r) return val;
        return mul(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
} *st, SegmentTree::mem[800000], *SegmentTree::ptr = mem;

vector<pair<int, int>> go(int a, int b) {
    vector<pair<int, int>> ret;
    int ta = top[a], tb = top[b];
    while (ta != tb) {
        if (dep[ta] < dep[tb]) {
            swap(a, b);
            swap(ta, tb);
        }
        ret.emplace_back(tin[ta], tin[a]);
        a = p[ta]; ta = top[a];
    }
    if (a == b) return ret;
    if (dep[a] > dep[b]) swap(a, b);
    ret.push_back(minmax(tin[maxson[a]], tin[b]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        G[a[i]].push_back(b[i]); G[b[i]].push_back(a[i]);
    }
    dfs(1, 0, 0); link(1, 1);
    st = new (SegmentTree::ptr++) SegmentTree(1, n);
    for (int i = 0; i < n - 1; ++i) {
        vid[i] = (dep[a[i]] >= dep[b[i]] ? tin[a[i]] : tin[b[i]]);
        st->modify(1, n, vid[i], c[i]);
    }
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int a, b; long long y; cin >> a >> b >> y;
            vector<pair<int, int>> p = go(a, b);
            long long qnow = 1ll;
            for (auto i : p) qnow = mul(qnow, st->query(1, n, i.first, i.second));
            cout << y / qnow << endl;
        } else {
            int p; long long c; cin >> p >> c;
            --p;
            st->modify(1, n, vid[p], c);
        }
    }
    return 0;
}