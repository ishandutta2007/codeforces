#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int a[maxn], pos[maxn], ans[maxn], n;
bool v[maxn];
vector<int> vec;

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    pair<int, int> p;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        if (L == R) {
            p = make_pair(pos[L], L);
            return;
        }
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        p = max(lc->p, rc->p);
    }
    void modify(int L, int R, int x, pair<int, int> v) {
        if (L == R) {
            p = v;
            return;
        }
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    }
    pair<int, int> query(int L, int R, int l, int r) {
        if (L > r || l > R) return make_pair(0, 0);
        if (L >= l && R <= r) return p;
        return max(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
#undef M
} *st;

void dfs(int now) {
    st->modify(1, n, now, make_pair(0, 0));
    v[now] = true;
    if (pos[now] != n + 1 && !v[pos[now]]) dfs(pos[now]);
    while (true) {
        pair<int, int> res = st->query(1, n, 1, a[now] - 1);
        if (res.first > now) dfs(res.second);
        else break;
    }
    vec.emplace_back(now);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    fill(pos, pos + maxn, n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == -1) a[i] = n + 1;
        else pos[a[i]] = i;
    }
    st = new SegmentTree(1, n);
    for (int i = 1; i <= n; ++i) if (!v[i]) dfs(i);
    int ind = 1;
    for (int u : vec) ans[u] = ind++;
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}