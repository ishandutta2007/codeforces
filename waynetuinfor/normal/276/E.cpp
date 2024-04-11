#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int id[maxn], pos[maxn], size[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int sum, tag;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        sum = tag = 0;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
    void push(int L, int R) {
        if (L == R || tag == 0) return;
        lc->sum += (M - L + 1) * tag; lc->tag += tag;
        rc->sum += (R - M) * tag; rc->tag += tag;
        tag = 0;
    }
    void modify(int L, int R, int l, int r, int v) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            sum += (R - L + 1) * v; tag += v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    int query(int L, int R, int x) {
        push(L, R);
        if (L == R) return sum;
        if (x <= M) return lc->query(L, M, x);
        else return rc->query(M + 1, R, x);
    }
#undef M
} *st[maxn], *nst;

void dfs(int now, int fa, int cnt, int p, int &tot) {
    id[now] = cnt; pos[now] = p;
    ++tot;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, cnt, p + 1, tot);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    int cnt = 0;
    for (int i : G[1]) {
        int tot = 0;
        dfs(i, 1, ++cnt, 1, tot);
        size[cnt] = tot;
    }
    for (int i = 1; i <= cnt; ++i) st[i] = new SegmentTree(1, size[i]);
    nst = new SegmentTree(0, n);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            if (x == 1) {
                cout << nst->query(0, n, 0) << endl;
                continue;
            }
            cout << nst->query(0, n, pos[x]) + st[id[x]]->query(1, size[id[x]], pos[x]) << endl;
        } else {
            int x, v, d; cin >> x >> v >> d;
            if (x == 1) {
                nst->modify(0, n, 0, d, v);
                continue;
            }
            st[id[x]]->modify(1, size[id[x]], max(1, pos[x] - d), min(pos[x] + d, size[id[x]]), v);
            int l = d - pos[x];
            if (l >= 0) {
                nst->modify(0, n, 0, l, v);
                st[id[x]]->modify(1, size[id[x]], 1, min(l, size[id[x]]), -v);
            }
        }
    }
    return 0;
}