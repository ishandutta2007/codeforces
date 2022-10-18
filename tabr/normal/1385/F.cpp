#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<set<int>> g(n);
        vector<int> deg(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace(y);
            g[y].emplace(x);
            deg[x]++, deg[y]++;
        }
        vector<int> l(n);
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                l[*g[i].begin()]++;
            }
        }
        int ans = 0;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.emplace(l[i], i);
        }
        while (pq.top().first >= k) {
            int v = pq.top().second;
            if (l[v] != pq.top().first) {
                pq.pop();
                continue;
            }
            pq.pop();
            l[v] -= k;
            deg[v] -= k;
            ans++;
            vector<int> t;
            for (int to : g[v]) {
                if (t.size() == k) {
                    break;
                }
                if (deg[to] == 1) {
                    t.emplace_back(to);
                }
            }
            for (int to : t) {
                l[to] = 0;
                deg[to]--;
                g[v].erase(to);
                g[to].clear();
                pq.emplace(0, to);
            }
            if (deg[v] == 1) {
                int to = *g[v].begin();
                l[to]++;
                pq.emplace(l[to], to);
            }
            pq.emplace(l[v], v);
        }
        cout << ans << '\n';
    }
    return 0;
}