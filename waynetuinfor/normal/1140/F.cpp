#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const int maxc = 3e5;
vector<pair<int, int>> edge[maxn * 4];
int fa[maxn], x[maxn], y[maxn], sz[maxn];

void init() {
    for (int i = 0; i < maxn; ++i) {
        fa[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < maxc; ++i) x[i] = 1;
    for (int i = maxc; i < maxc + maxc; ++i) y[i] = 1;
}

void modify(int l, int r, int ql, int qr, int x, int y, int o = 0) {
    if (l >= qr || ql >= r) return;
    if (l >= ql && r <= qr) {
        edge[o].emplace_back(x, y);
        return;
    }
    modify(l, (l + r) >> 1, ql, qr, x, y, o * 2 + 1);
    modify((l + r) >> 1, r, ql, qr, x, y, o * 2 + 2);
}

vector<int> snapshot;
vector<pair<int*, int>> history;

int find(int x) {
    if (x == fa[x]) return x;
    return find(fa[x]);
}

void assign(int *x, int v) {
    history.emplace_back(x, *x);
    *x = v;
}

void merge(int u, int v, long long &dlt) {
    if ((u = find(u)) == (v = find(v)))
        return;
    if (sz[u] > sz[v])
        swap(u, v);

    dlt -= x[u] * 1ll * y[u];
    dlt -= x[v] * 1ll * y[v];
    assign(&sz[v], sz[u] + sz[v]);    
    assign(&x[v], x[v] + x[u]);
    assign(&y[v], y[v] + y[u]);
    assign(&fa[u], v);
    dlt += x[v] * 1ll * y[v];
}

void undo() {
    int target = snapshot.back();
    snapshot.pop_back();

    while ((int)history.size() > target) {
        int *x = history.back().first;
        int v = history.back().second;
        history.pop_back();
        *x = v;
    }
}

void traverse(int l, int r, int o = 0, long long ans = 0) {
    long long dlt = 0;
    snapshot.push_back((int)history.size());
    for (int i = 0; i < (int)edge[o].size(); ++i)
        merge(edge[o][i].first, edge[o][i].second + maxc, dlt);

    ans += dlt;
    if (r - l == 1) {
        printf("%lld ", ans);
    } else {
        traverse(l, (l + r) >> 1, o * 2 + 1, ans);
        traverse((l + r) >> 1, r, o * 2 + 2, ans);
    }
    ans -= dlt;
    undo();
}

int main() {
    int q; scanf("%d", &q);
    map<pair<int, int>, int> last;
    for (int i = 0; i < q; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        if (last.find(make_pair(x, y)) != last.end()) {
            modify(0, q, last[make_pair(x, y)], i, x, y);
            last.erase(make_pair(x, y));
        } else {
            last[make_pair(x, y)] = i;
        }
    }

    for (auto it : last)
        modify(0, q, it.second, q, it.first.first, it.first.second);

    init();
    traverse(0, q);
    puts("");
}