#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9;
vector<int> G[maxn];
bool pos[maxn];
int s, t;

template <typename T> using heap = priority_queue<T, vector<T>, greater<T>>;

bool check(int q) {
    // cout << "check q = " << q << endl;
    vector<int> dis(maxn, inf);
    bitset<maxn> v;
    heap<pair<int, int>> pq;
    dis[s] = 0; pq.push(make_pair(0, s));
    while (pq.size()) {
        int d, p; tie(d, p) = pq.top(); pq.pop();
        // cout << "d = " << d << " p = " << p << endl;
        if (d > q) continue;
        // v[p] = true;
        for (int u : G[p]) {
            if (pos[p]) if (1 < dis[u]) pq.push(make_pair(dis[u] = 1, u));
            if (!pos[p]) if (d + 1 < dis[u]) pq.push(make_pair(dis[u] = d + 1, u));
        }
    }
    // for (int i = 1; i <= n; ++i) cout << dis[i] << ' '; cout << endl;
    return dis[t] <= q;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int p; cin >> p; pos[p] = true;
    }
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    cin >> s >> t;
    int d = 21, q = n + 1; 
    while (d--) if (q - (1 << d) >= 0) if (check(q - (1 << d))) q -= (1 << d);
    cout << (q == n + 1 ? -1 : q) << endl;
    return 0;
}