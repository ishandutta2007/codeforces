#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10, inf = 1e9 + 1, mem = 2e7 + 10;
int a[maxn], pos[maxn];
int val[mem], lc[mem], rc[mem], st[maxn];
int ptr;

#define M ((L + R) >> 1)
void build(int id, int L, int R) {
    val[id] = inf;
    if (L == R) return;
    lc[id] = ++ptr;
    rc[id] = ++ptr;
    build(lc[id], L, M); 
    build(rc[id], M + 1, R);
}

void pull(int id) {
    val[id] = min(val[lc[id]], val[rc[id]]);
}

int modify(int id, int L, int R, int x, int v) {
    int cur = ++ptr;
    val[cur] = val[id]; lc[cur] = lc[id]; rc[cur] = rc[id];
    if (L == R) {
        val[cur] = min(val[cur], v);
        return cur;
    }
    if (x <= M) lc[cur] = modify(lc[id], L, M, x, v);
    else rc[cur] = modify(rc[id], M + 1, R, x, v);
    pull(cur);
}

int query(int id, int L, int R, int l, int r) {
    if (L > r || l > R) return inf;
    if (L >= l && R <= r) return val[id];
    return min(query(lc[id], L, M, l, r), query(rc[id], M + 1, R, l, r));
}
#undef M

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> v;
    for (int i = 1; i <= n; ++i) cin >> a[i], v.push_back(a[i]);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    st[0] = 1; ++ptr;
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        if (pos[a[i]]) {
            st[i] = modify(st[i - 1], 1, n, pos[a[i]], i - pos[a[i]]);
            pos[a[i]] = i;
        } else {
            st[i] = st[i - 1];
            pos[a[i]] = i;
        }
    }
    while (m--) {
        int l, r; cin >> l >> r;
        int ans = query(st[r], 1, n, l, r);
        if (ans == inf) ans = -1;
        cout << ans << endl;
    }
    return 0;
}