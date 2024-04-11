#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
long long ans;
pair <long long, long long> a[N];
 
bool cmp(pair <long long, long long> x, pair <long long, long long> y) {
    if (x.second != y.second) {
        return x.second < y.second;
    } else {
        return x.first < y.first;
    }
}

vector <long long> segmenttree[4 * N], segmenttree2[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        segmenttree[id] = {a[l].first};
        segmenttree2[id] = {a[l].first};
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    merge(segmenttree[id << 1].begin(), segmenttree[id << 1].end(),
          segmenttree[id << 1 | 1].begin(), segmenttree[id << 1 | 1].end(),
          back_inserter(segmenttree[id]));
    segmenttree2[id].resize(r - l + 1);
    segmenttree2[id][r - l] = segmenttree[id][r - l];
    for (int i = r - l - 1; i >= 0; i--) {
        segmenttree2[id][i] = segmenttree2[id][i + 1] + segmenttree[id][i];
    }
}

long long get(int id, int l, int r, int u, int v, long long val) {
    if (v < l || r < u) {
        return 0;
    }
    if (u <= l && r <= v) {
        long long idx = lower_bound(segmenttree[id].begin(), segmenttree[id].end(), val) - segmenttree[id].begin();
        if (idx == r - l + 1) {
            return 0;
        } else {
            return segmenttree2[id][idx] - (r - l + 1 - idx) * val;
        }
    }
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v, val) + get(id << 1 | 1, mid + 1, r, u, v, val);
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
    }
    sort(a + 1, a + 1 + n, cmp);
    build(1, 1, n);
    for (int i = 1; i < n; i++) {
        ans += get(1, 1, n, i + 1, n, a[i].first);
    }
    cout << ans;
}
 
/*
==================================+
INPUT:                            |
------------------------------    |
 
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
 
------------------------------    |
==================================+
*/