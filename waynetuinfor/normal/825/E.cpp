#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int deg[maxn], p[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        G[b].push_back(a); ++deg[a];
    }
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 1; i <= n; ++i) if (deg[i] == 0) pq.push(i);
    for (int i = n; i > 0; --i) {
        int k = pq.top(); pq.pop();
        p[k] = i;
        for (int u : G[k]) if (--deg[u] == 0) pq.push(u);
    }
    for (int i = 1; i <= n; ++i) cout << p[i] << ' '; cout << endl;
    return 0;
}