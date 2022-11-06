#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = 1e18 + 1;
int a[maxn];
pair<long long, long long> p[maxn];

long long dis(const pair<long long, long long>& a, const pair<long long, long long>& b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

long long rec(int l, int r) {
    if (l == r) return inf;
    if (r - l == 1) return dis(p[l], p[r]);
    int m = (l + r) >> 1;
    long long d = min(rec(l, m), rec(m, r));
    vector<int> vec;
    for (int i = m; i >= l && (p[m].first - p[i].first) * (p[m].first - p[i].first) < d; --i) vec.push_back(i);
    for (int i = m + 1; i <= r && (p[i].first - p[m].first) * (p[i].first - p[m].first) < d; ++i) vec.push_back(i);
    sort(vec.begin(), vec.end(), [=](const int& a, const int& b) { return p[a].second < p[b].second; });
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = i + 1; j < vec.size() && (p[vec[i]].second - p[vec[j]].second) * (p[vec[i]].second - p[vec[j]].second) < d; ++j) {
            d = min(d, dis(p[vec[i]], p[vec[j]]));
        }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long s = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        p[i] = make_pair(i, s);
    }
    sort(p, p + n);
    cout << rec(0, n - 1) << endl;
}