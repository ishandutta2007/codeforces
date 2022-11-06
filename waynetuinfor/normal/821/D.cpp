#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10, inf = 1e9 + 1;
pair<int, int> p[maxn];
// vector<pair<int, int>> G[maxn];
int d[maxn];
bool v[maxn];

int main() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) cin >> p[i].first >> p[i].second;
    fill(d, d + maxn, inf);
    d[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));
    while (pq.size()) {
        pair<int, int> tmp = pq.top(); pq.pop();
        if (v[tmp.second]) continue;
        v[tmp.second] = true;
        for (int i = 0; i < k; ++i) if (i != tmp.second) {
            int a = abs(p[tmp.second].first - p[i].first), b = abs(p[tmp.second].second - p[i].second);
            if (a == 0 && b == 1 || a == 1 && b == 0) {
                if (tmp.first < d[i]) d[i] = tmp.first, pq.push(make_pair(d[i], i));
            } else if (a <= 2 || b <= 2) {
                if (tmp.first + 1 < d[i]) d[i] = tmp.first + 1, pq.push(make_pair(d[i], i));
            }
        }
        int a = abs(p[tmp.second].first - n), b = abs(p[tmp.second].second - m);
        if (a == 0 && b == 0) {
            if (tmp.first < d[k]) d[k] = tmp.first, pq.push(make_pair(d[k], k));
        } else if (a <= 1 || b <= 1) {
            if (tmp.first + 1 < d[k]) d[k] = tmp.first + 1, pq.push(make_pair(d[k], k));
        }
    }
    int ans = d[k] == inf ? -1 : d[k]; cout << ans << endl;
    return 0;
}