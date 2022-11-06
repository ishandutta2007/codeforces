#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int x[maxn], y[maxn], c[maxn];
int q[maxn], l, r;
vector<int> vx[maxn], vy[maxn], graf[maxn];

void add_edge(int a, int b) {
    graf[a].push_back(b);
    graf[b].push_back(a);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", x + i, y + i);
        vx[x[i]].push_back(i);
        vy[y[i]].push_back(i);
    }
    for (int i = 0; i < maxn; ++i) if (vx[i].size()) {
        sort(vx[i].begin(), vx[i].end(), [&](const int &a, const int &b) { return y[a] < y[b]; });
        for (int j = 0; j + 1 < vx[i].size(); j += 2) add_edge(vx[i][j], vx[i][j + 1]);
    }
    for (int i = 0; i < maxn; ++i) if (vy[i].size()) {
        sort(vy[i].begin(), vy[i].end(), [&](const int &a, const int &b) { return x[a] < x[b]; });
        for (int j = 0; j + 1 < vy[i].size(); j += 2) add_edge(vy[i][j], vy[i][j + 1]);
    }
    memset(c, -1, sizeof(c));
    for (int i = 0; i < n; ++i) if (c[i] == -1) {
        c[i] = 0; l = r = 0;
        q[r++] = i;
        while (l < r) {
            int x = q[l++];
            for (int u : graf[x]) {
                if (c[u] == -1) c[u] = (c[x] ^ 1), q[r++] = u;
            }
        }
    }
    for (int i = 0; i < n; ++i) putchar("br"[c[i]]); puts("");
    return 0;
}