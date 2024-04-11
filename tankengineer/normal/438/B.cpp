#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

const int N = 100005;

int a[N], ord[N];

bool by_a(int i, int j) {
    return a[i] > a[j];
}

int fa[N], size[N];
bool appear[N];

int find(int u){
    return u == fa[u] ? fa[u] : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    fa[u] = v;
    size[v] += size[u];
}

vector<int> edge[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        ord[i] = i;
    }
    sort(ord, ord + n, by_a);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        fa[i] = i, size[i] = 1, appear[i] = false;
    }
    long double ans = 0;
    for (int i = 0 ; i < n; ++i) {
        int u = ord[i];
        appear[u] = true;
        vector<int> block;
        block.push_back(1);
        for (int j = 0; j < (int)edge[u].size(); ++j) {
            int v = edge[u][j];
            if (!appear[v]) {
                continue;
            }
            if (find(u) != find(v)) {
                block.push_back(size[find(v)]);
                merge(find(u), find(v));
            }
        }
        for (int i = 0; i < (int)block.size(); ++i) {
            ans += (long double)(size[find(u)] - block[i]) * block[i] * a[u];
        }
    }
    printf("%.12f\n", (double)(ans / n / (n - 1)));
    return 0;
}