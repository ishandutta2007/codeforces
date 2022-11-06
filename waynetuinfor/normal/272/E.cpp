#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
vector<int> graf[maxn];
int ans[maxn], p[maxn], q[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        graf[a].push_back(b); graf[b].push_back(a);
    }
    for (int i = 1; i <= n / 2; ++i) ans[i] = 0;
    for (int i = n / 2 + 1; i <= n; ++i) ans[i] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int u : graf[i]) {
            if (ans[u] != ans[i]) ++q[i];
            else ++p[i];
        }
    }
    set<pair<int, int>> s;
    for (int i = 1; i <= n; ++i) s.insert(make_pair(q[i] - p[i], i));
    while (true) {
        int diff, now; tie(diff, now) = *s.begin();
        if (diff >= 0) break;
        s.erase(make_pair(diff, now));
        p[now] = q[now] = 0; ans[now] ^= 1;
        for (int u : graf[now]) {
            if (ans[now] == ans[u]) ++p[now];
            else ++q[now];
        }
        s.insert(make_pair(q[now] - p[now], now));
        for (int u : graf[now]) s.erase(make_pair(q[u] - p[u], u));
        for (int u : graf[now]) {
            p[u] = q[u] = 0;
            for (int k : graf[u]) {
                if (ans[k] == ans[u]) ++p[u];
                else ++q[u];
            }
            s.insert(make_pair(q[u] - p[u], u));
        }
    }
    for (int i = 1; i <= n; ++i) printf("%d", ans[i]); puts("");
    return 0;
}