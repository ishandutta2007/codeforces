#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<int> graf[maxn], ans;
int p[maxn], deg[maxn], sz[maxn], odd[maxn], n;
unordered_map<int, int> szz[maxn];
bool v[maxn];

void dfssz(int now, int fa) {
    sz[now] = 1;
    for (int u : graf[now]) if (u != fa) {
        dfssz(u, now);
        sz[now] += sz[u];
        szz[now][u] = sz[u];
    }
    if (fa) szz[now][fa] = n - sz[now];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
    for (int i = 1; i <= n; ++i) if (p[i]) {
        graf[i].push_back(p[i]);
        graf[p[i]].push_back(i);
        ++deg[p[i]], ++deg[i];
    }
    if (n % 2 == 0) return 0 * puts("NO");
    puts("YES");
    dfssz(1, 0);
    for (int i = 1; i <= n; ++i) {
        for (auto it : szz[i]) {
            if (it.second % 2 == 1) ++odd[i];
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] % 2 == 0 && odd[i] == deg[i]) {
            v[i] = true;
            q.push(i);
            ans.push_back(i);
        }
    }
    while (q.size()) {
        int now = q.front(); q.pop();
        for (int u : graf[now]) {
            --deg[u];
            if (szz[u][now] & 1) --odd[u];
            if (deg[u] % 2 == 0 && odd[u] == deg[u] && !v[u]) {
                v[u] = true;
                ans.push_back(u);
                q.push(u);
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i) printf("%d\n", ans[i]);
    return 0;
}