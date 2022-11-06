#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int p[maxn], a[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    queue<int> q;
    for (int i = 1; i <= n; ++i) if (a[i] == 0) q.push(i);
    vector<int> ans;
    while (q.size()) {
        int now = q.front(); q.pop();
        if (p[now] > a[now]) continue;
        v[now] = true;
        ++p[now];
        ans.push_back(now);
        for (int u : G[now]) {
            ++p[u];
            if (p[u] == a[u]) {
                if (v[u]) return cout << "-1" << endl, 0;
                q.push(u);
            }
        }
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' '; cout << endl;
}