#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int maxc = 2520;
int e[maxn][10], k[maxn], m[maxn], has[maxn * maxc];
int to[maxn * maxc], fa[maxn * maxc], deg[maxn * maxc], sz[maxn * maxc];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    sz[y] += sz[x];
    fa[x] = y;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &k[i]);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m[i]);
        for (int j = 0; j < m[i]; ++j) {
            scanf("%d", &e[i][j]);
            --e[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < maxc; ++j) {
            int nxt = ((j + k[i]) % m[i] + m[i]) % m[i];
            to[i * maxc + j] = e[i][nxt] * maxc + ((j + k[i]) % maxc + maxc) % maxc;
            ++deg[to[i * maxc + j]];
        }
    }
    for (int i = 0; i < n * maxc; ++i) fa[i] = i, sz[i] = 1, has[i] = 1;
    for (int i = 0; i < n * maxc; ++i) merge(i, to[i]);

    queue<int> qu;
    for (int i = 0; i < n * maxc; ++i) {
        if (deg[i] == 0) qu.push(i);
    }
    while (!qu.empty()) {
        int x = qu.front(); qu.pop();
        --sz[find(x)];
        has[x] = 0;
        if (--deg[to[x]] == 0) qu.push(to[x]);
    }

    for (int i = 0; i < n; ++i) {
        map<int, int> z;
        for (int j = 0; j < maxc; ++j) z[find(i * maxc + j)] += has[i * maxc + j];
        for (auto it : z) {
            if (it.second > 1) sz[it.first] -= it.second - 1;
        }
    }
    
    int q; scanf("%d", &q);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y); --x;
        ((y %= maxc) += maxc) %= maxc;
        printf("%d\n", sz[find(x * maxc + y)]);
    }
    return 0;
}