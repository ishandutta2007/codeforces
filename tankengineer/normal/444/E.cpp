#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3005;

int n;
vector<pair<int, int> > edge[N];

int c[N];

int fa[N];

int cnt[N], sigma[N];

int find(int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    fa[v] = u;
}

void dfs(int u, int bar, int fa = -1) {
    for (int i = 0; i < (int)edge[u].size(); ++i) {
        int v = edge[u][i].first, d = edge[u][i].second;
        if (v == fa) {
            continue;
        }
        dfs(v, bar, u);
        if (d < bar) {
            merge(find(v), find(u));
        }
    }
}

bool check(int bar) {
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
    }
    dfs(0, bar);
    for (int i = 0; i < n; ++i) {
        cnt[i] = 0, sigma[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        ++cnt[find(i)], sigma[find(i)] += c[i];
    }
    int maxcnt = find(0), sum = 0;
    for (int i = 0; i < n; ++i) {
        if (find(i) == i) {
            if (cnt[i] > cnt[maxcnt]) {
                maxcnt = i;
            }
            sum += sigma[i];
        }
    }
    return sum - sigma[maxcnt] >= cnt[maxcnt];
}

int main() {
    scanf("%d", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    vector<int> val;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        --u, --v;
        edge[u].push_back(make_pair(v, w));
        edge[v].push_back(make_pair(u, w));
        val.push_back(w);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for (int i = 0; i < n; ++i) {
        scanf("%d", c + i);
    }
    int l = 0, r = (int)val.size() - 1;
    while (l < r) {
        int m = l + r + 1 >> 1;
        if (check(val[m])) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    printf("%d\n", val[l]);
    return 0;
}