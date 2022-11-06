#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
pair<int, int> a[maxn];
pair<pair<int, int>, int> p[maxn];
int n, m, s;
vector<int> vec;

bool check(int d) {
    vector<int> cnt(n, 0), tmp(m, -1);
    int ind = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int cost = 0;
    for (int i = 0; i < m; ++i) {
        while (ind < n && p[ind].first.first >= a[i].first) pq.push(make_pair(p[ind].first.second, p[ind].second)), ++ind;
        while (pq.size() && cnt[pq.top().second] >= d) pq.pop();
        if (pq.size() == 0) return false;
        tmp[a[i].second] = pq.top().second;
        if (cnt[pq.top().second] == 0) cost += pq.top().first, pq.push(make_pair(0, pq.top().second));
        ++cnt[pq.top().second];
    }
    if (cost > s) return false;
    vec = tmp;
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) cin >> a[i].first, a[i].second = i;
    for (int i = 0; i < n; ++i) cin >> p[i].first.first;
    for (int i = 0; i < n; ++i) cin >> p[i].first.second, p[i].second = i;
    sort(a, a + m); sort(p, p + n); reverse(a, a + m); reverse(p, p + n);
    int d = 1, ans = m + 1; while (d <= m) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    if (ans == m + 1) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    for (int i = 0; i < m; ++i) cout << vec[i] + 1 << ' '; cout << endl;
    return 0;
}