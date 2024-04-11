#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n;

vector<int> edge[N], edge2[N];

vector<int> ord;

const int LOG = 17;

int rnk[N], out[N], dep[N], fa[N][LOG];

void dfs(int u) {
    rnk[u] = ord.size();
    ord.push_back(u);
    for (int j = 0; j < (int)edge[u].size(); ++j) {
        int v = edge[u][j];
        if (v == fa[u][0]) {
            continue;
        }
        fa[v][0] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
    out[u] = ord.size() - 1;
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    int delta = dep[u] - dep[v];
    for (int i = LOG - 1; i >= 0; --i) {
        if (delta >> i & 1) {
            u = fa[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = LOG - 1; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int vis[N], stamp;

int sum[N << 1], tag[N << 1];

inline int getID(int l, int r) {
    return (l + r) | (l != r);
}

void init(int l, int r) {
    int x = getID(l, r);
    sum[x] = 0;
    tag[x] = -1;
    if (l != r) {
        int m = (l + r) >> 1;
        init(l, m);
        init(m + 1, r);
    }
}

void covern(int l, int r, int v) {
    int x = getID(l, r);
    tag[x] = v, sum[x] = v * (r - l + 1);
}

void update(int l, int r) {
    int x = getID(l, r), m = (l + r) >> 1, lc = getID(l, m), rc = getID(m + 1, r);
    sum[x] = sum[lc] + sum[rc];
}

void pushdown(int l, int r) {
    int x = getID(l, r);
    if (tag[x] != -1) {
        int m = (l + r) >> 1;
        covern(l, m, tag[x]);
        covern(m + 1, r, tag[x]);
        tag[x] = -1;
    }
}

void cover(int l, int r, int a, int b, int v) {
    if (b < l || r < a) {
        return;
    }
    if (a <= l && r <= b) {
        covern(l, r, v);
    } else {
        int m = (l + r) >> 1;
        pushdown(l, r);
        cover(l, m, a, b, v);
        cover(m + 1, r, a, b, v);
        update(l, r);
    }
}

int getsum(int l, int r, int a, int b) {
    if (b < l || r < a) {
        return 0;
    }
    if (a <= l && r <= b) {
        return sum[getID(l, r)];
    } else {
        int m = (l + r) >> 1;
        pushdown(l, r);
        return getsum(l, m, a, b) + getsum(m + 1, r, a, b);
    }
}

bool byRnk(const int &i, const int &j) {
    return rnk[i] < rnk[j];
}

bool byDep(const int &i, const int &j) {
    return dep[i] < dep[j];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    memset(fa, -1, sizeof(fa));
    dfs(0);
    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i < n; ++i) {
            if (fa[i][j - 1] == -1) {
                fa[i][j] = -1;
            } else {
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
            }
        }
    }
    init(0, n - 1);
    int q;
    scanf("%d", &q);
    while (q--) {
        cover(0, n - 1, 0, n - 1, 0);
        int m;
        scanf("%d", &m);
        vector<int> us(m);
        ++stamp;
        for (int i = 0; i < m; ++i) {
            scanf("%d", &us[i]);
            --us[i];
            vis[us[i]] = stamp;
            cover(0, n - 1, rnk[us[i]], rnk[us[i]], 1);
        }
        bool flag = false;
        for (int i = 0; i < m; ++i) {
            int u = us[i];
            if (fa[u][0] != -1 && vis[fa[u][0]] == stamp) {
                flag = true;
                break;
            }
        }
        if (flag) {
            printf("-1\n");
            continue;
        }
        sort(us.begin(), us.end(), byRnk);
        vector<int> fs;
        for (int i = 0; i < m; ++i) {
            int u = us[i], v = us[(i + 1) % m];
            fs.push_back(lca(u, v));
        }
        sort(fs.begin(), fs.end());
        fs.erase(unique(fs.begin(), fs.end()), fs.end());
        sort(fs.begin(), fs.end(), byDep);
        int ans = 0;
        for (int i = (int)fs.size() - 1; i >= 0; --i) {
            int u = fs[i];
            int k = getsum(0, n - 1, rnk[u], out[u]);
            if (k > 1) {
                if (vis[u] == stamp) {
                    ans += k - 1;
                    cover(0, n - 1, rnk[u] + 1, out[u], 0);
                } else {
                    ++ans;
                    cover(0, n - 1, rnk[u], out[u], 0);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}