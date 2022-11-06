#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int c[maxn];
vector<int> graf[maxn], v[maxn];
bool z[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", c + i), v[c[i]].push_back(i);
    while (m--) {
        int a, b; scanf("%d %d", &a, &b); --a; --b;
        graf[a].push_back(b); graf[b].push_back(a);
    }
    int ans = -1, mxc = -1;
    for (int i = 1; i <= 100000; ++i) if (v[i].size() > 0) {
        int p = 0;
        for (int u : v[i]) for (int k : graf[u]) if (!z[c[k]] && c[k] != i) z[c[k]] = true, ++p;
        for (int u : v[i]) for (int k : graf[u]) z[c[k]] = false;
        if (p > mxc) mxc = p, ans = i;
    }
    printf("%d\n", ans);
    return 0;
}