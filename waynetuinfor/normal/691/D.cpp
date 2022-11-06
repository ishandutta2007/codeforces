#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int p[maxn], ind, ans[maxn];
bool v[maxn];
vector<int> G[maxn];
priority_queue<int> pq[maxn];
priority_queue<int, vector<int>, greater<int>> pos[maxn];

void dfs(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) if (!v[i]) {
        ++ind; dfs(i);
    }
    for (int i = 1; i <= ind; ++i) {
        while (pq[i].size()) ans[pos[i].top()] = pq[i].top(), pq[i].pop(), pos[i].pop();
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}

void dfs(int x) {
    pos[ind].push(x); pq[ind].push(p[x]);
    v[x] = true;
    for (int u : G[x]) if (!v[u]) dfs(u);
}