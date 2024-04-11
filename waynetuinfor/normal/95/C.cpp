#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1000 + 10, inf = 1e15;
int t[maxn], c[maxn], d[maxn], n, m;
bool v[maxn];

vector<pair<int, int>> G[maxn], pre[maxn];

void init() {
    for (int i = 1; i <= n; ++i) {
        vector<int> w(maxn, inf);
        bitset<maxn> vis;
        w[i] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, i));
        while (pq.size()) {
            pair<int, int> p = pq.top(); pq.pop();
            if (vis[p.second]) continue;
            vis[p.second] = true;
            for (auto e : pre[p.second]) {
                if (w[e.first] > p.first + e.second) {
                    w[e.first] = p.first + e.second;
                    pq.push(make_pair(w[e.first], e.first));
                }
            }
        }
        for (int j = 1; j <= n; ++j) {
            if (w[j] <= t[i]) G[i].push_back(make_pair(j, c[i]));
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x, y; cin >> n >> m >> x >> y;
    if (x == y) return cout << "0" << endl, 0;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        pre[a].push_back(make_pair(b, c));
        pre[b].push_back(make_pair(a, c));
    }
    for (int i = 1; i <= n; ++i) cin >> t[i] >> c[i];
    init();
    d[x] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(d, d + maxn, inf);
    pq.push(make_pair(0, x));
    while (pq.size()) {
        pair<int, int> p = pq.top(); pq.pop();
        if (v[p.second]) continue;
        v[p.second] = true;
        for (auto e : G[p.second]) {
            if (d[e.first] > p.first + e.second) {
                d[e.first] = p.first + e.second;
                pq.push(make_pair(d[e.first], e.first));
            }
        }
    }
    cout << (d[y] == inf ? -1 : d[y]) << endl;
    return 0;
}