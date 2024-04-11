#include <bits/stdc++.h>
using namespace std;

const int maxn = 300000 + 5;
multiset<int> ms;
vector<int> G[maxn];
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ms.insert(a[i] + 2);
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        int tmp = INT_MIN;
        ms.erase(ms.find(a[i] + 2)); tmp = max(tmp, a[i]);
        for (int u : G[i]) ms.erase(ms.find(a[u] + 2)), tmp = max(tmp, a[u] + 1);
        if (ms.size()) tmp = max(tmp, *ms.rbegin());
        ms.insert(a[i] + 2);
        for (int u : G[i]) ms.insert(a[u] + 2);
        ans = min(ans, tmp);
    }
    cout << ans << '\n';
    return 0;
}