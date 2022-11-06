#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, inf = 1e9 + 1;
vector<pair<int, int>> G[maxn];
pair<int, int> p[maxn];
int a[maxn], dis[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, d; cin >> n >> d;
    for (int i = 2; i < n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> p[i].first >> p[i].second;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            G[i].push_back(make_pair(j, d * (abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second))));
            G[j].push_back(make_pair(i, d * (abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second))));
        }
    }
    fill(dis, dis + maxn, inf);
    dis[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; pq.push(make_pair(0, 1));
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        if (v[p.second]) continue;
        v[p.second] = true;
        for (auto e : G[p.second]) {
            int w = e.second;
            if (e.first >= 2 && e.first < n) w -= a[e.first];
            if (dis[e.first] > p.first + w) {
                dis[e.first] = p.first + w;
                pq.push(make_pair(dis[e.first], e.first));
            }
        }
    }
    cout << dis[n] << endl;
    return 0;
}