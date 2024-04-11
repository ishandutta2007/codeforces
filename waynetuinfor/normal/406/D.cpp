#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, lg = 20;
long long x[maxn], y[maxn];
int uto[maxn];
int to[lg][maxn], dep[maxn];

int lca(int a, int b) {
    if (a == b) return a;
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = 0; i < lg; ++i) {
        if ((dep[b] - dep[a]) >> i & 1) b = to[i][b];
    }
    if (a == b) return a;
    for (int i = lg - 1; i >= 0; --i) {
        if (to[i][a] != to[i][b]) a = to[i][a], b = to[i][b];
        if (a == b) return a;
    }
    return to[0][a];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld %lld", x + i, y + i);
    deque<int> dq;
    for (int i = n; i >= 1; --i) {
        while (dq.size() >= 2 && 
              (y[dq[0]] - y[i]) * 1ll * (x[dq[1]] - x[i]) < (y[dq[1]] - y[i]) * 1ll * (x[dq[0]] - x[i])) dq.pop_front();
        if (dq.size()) uto[i] = dq.front();
        dq.push_front(i);
    }
    for (int i = 1; i <= n; ++i) to[0][i] = uto[i];
    for (int i = 1; i < lg; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (to[i - 1][j]) to[i][j] = to[i - 1][to[i - 1][j]];
        }
    }
    for (int i = n; i >= 0; --i) {
        if (!to[0][i]) dep[i] = 0;
        else dep[i] = dep[to[0][i]] + 1;
    } 
    int m; scanf("%d", &m);
    while (m--) {
        int l, r; scanf("%d %d", &l, &r);
        printf("%d ", lca(l, r)); 
    }
    puts("");
}