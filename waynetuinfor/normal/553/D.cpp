#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> graf[maxn], ans;
bool forb[maxn], v[maxn];
int n, deg[maxn];

bool check(double r, bool o = false) {
    // printf("check r = %lf\n", r);
    queue<int> q;
    for (int i = 1; i <= n; ++i) if (forb[i]) q.push(i);
    vector<int> ndeg(deg, deg + maxn);
    memset(v, false, sizeof(v));
    while (q.size()) {
        // printf("q.front() = %d\n", q.front());
        int now = q.front(); q.pop();
        if (v[now]) continue;
        v[now] = true;
        for (int u : graf[now]) {
            --ndeg[u];
            if (ndeg[u] < r * 1.0 * deg[u]) q.push(u);
        }
    }
    vector<int> res;
    for (int i = 1; i <= n; ++i) if (!v[i]) res.push_back(i);
    if (res.size() && o) ans = res;
    return res.size() > 0;
}

int main() {
    int m, k; scanf("%d %d %d", &n, &m, &k);
    while (k--) {
        int t; scanf("%d", &t);
        forb[t] = true;
    }
    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        graf[a].push_back(b); graf[b].push_back(a);
        ++deg[a]; ++deg[b];
    }
    double l = 0, r = maxn;
    int step = 50;
    while (step--) {
        double m = (l + r) / 2.0;
        if (check(m)) l = m;
        else r = m;
    }
    check(l, true);
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]); puts("");
    return 0;
}