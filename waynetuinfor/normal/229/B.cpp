#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = 1e18;
vector<pair<int, int>> G[maxn];
vector<pair<long long, long long>> itv[maxn];
long long d[maxn];
bool v[maxn];

template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using max_heap = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m; while (m--) {
        int a, b, c; cin >> a >> b >> c;
        G[a].emplace_back(b, c); G[b].emplace_back(a, c);
    }
    for (int i = 1; i <= n; ++i) {
        int k, prv = -1; cin >> k;
        for (int j = 0; j < k; ++j) {
            int t; cin >> t;
            if (t - 1 >= prv + 1) itv[i].emplace_back(prv + 1, t - 1);
            prv = t;
        }
        itv[i].emplace_back(prv + 1, inf);
        sort(itv[i].begin(), itv[i].end());
    }
    auto cmpl = [](const pair<long long, long long> &a, const pair<long long, long long> &b) { return a.second < b.second; };
    auto cmpr = [](const pair<long long, long long> &a, const pair<long long, long long> &b) { return a.second < b.second; };
    fill(d, d + maxn, inf);
    d[1] = 0;
    min_heap<pair<long long, int>> pq; pq.emplace(0, 1);
    while (pq.size()) {
        int t, now; tie(t, now) = pq.top(); pq.pop();
        if (v[now]) continue;
        v[now] = true;
        if ((*lower_bound(itv[now].begin(), itv[now].end(), make_pair(t, t), cmpr)).first > t) {
            t = (*lower_bound(itv[now].begin(), itv[now].end(), make_pair(t, t), cmpl)).first;
        } 
        for (auto u : G[now]) {
            if (t + u.second < d[u.first]) pq.emplace(d[u.first] = t + u.second, u.first);
        }
    }
    cout << (d[n] == inf ? -1 : d[n]) << endl;
    return 0;
}