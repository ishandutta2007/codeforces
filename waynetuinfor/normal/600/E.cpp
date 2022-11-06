#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
int c[maxn], arr[maxn], tin[maxn], tout[maxn], t, bst, data[2][maxn], cnt[maxn], ans[maxn];
vector<int> G[maxn];

struct query {
    int l, r, block, id;
    bool operator<(const query& rhs) const {
        return block == rhs.block ? r < rhs.r : block < rhs.block;
    }
};

void dfs(int now, int fa) {
    tin[now] = ++t;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
    }
    tout[now] = t;
}

void add(int now) {
    now = arr[now];
    --data[0][cnt[now]]; data[1][cnt[now]] -= now;
    ++cnt[now];
    ++data[0][cnt[now]]; data[1][cnt[now]] += now; 
    while (data[0][bst + 1]) ++bst;
}

void sub(int now) {
    now = arr[now];
    --data[0][cnt[now]]; data[1][cnt[now]] -= now;
    --cnt[now];
    ++data[0][cnt[now]]; data[1][cnt[now]] += now; 
    while (!data[0][bst]) --bst;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b); G[b].emplace_back(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) arr[tin[i]] = c[i];
    vector<query> q;
    int lim = 1 + (int)sqrt(n);
    for (int i = 1; i <= n; ++i) q.push_back((query){ tin[i], tout[i], tin[i] / lim, i });
    sort(q.begin(), q.end());
    int l = 1, r = 0;
    for (auto i : q) {
        while (r < i.r) add(++r);
        while (r > i.r) sub(r--);
        while (l > i.l) add(--l);
        while (l < i.l) sub(l++);
        ans[i.id] = data[1][bst];
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}