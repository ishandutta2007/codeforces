#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int ans[maxn];

struct fenwick {
    int data[maxn];
    void init() { memset(data, 0, sizeof(data)); }
    void add(int x, int v) { for (; x < maxn; x += x & -x) data[x] += v; }
    int qry(int x, int ret = 0) { for (; x; x -= x & -x) ret += data[x]; return ret; }
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> segs;
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        segs.emplace_back(l, r);
    }
    sort(segs.begin(), segs.end(), [](const auto &a, const auto &b) { return a.second > b.second; });
    vector<pair<int, pair<int, int>>> points;
    for (int i = 0; i < m; ++i) {
        int c, p; cin >> c; 
        vector<int> now;
        while (c--) cin >> p, now.push_back(p);
        sort(now.begin(), now.end());
        int prv = 1;
        for (int j : now) {
            if (j >= prv) points.emplace_back(j, make_pair(prv, i));
            prv = j + 1;
        }
    }
    sort(points.begin(), points.end(), [](const auto &a, const auto &b) { return a.first > b.first; });
    size_t ptr = 0;
    bit.init();
    for (auto pt : points) {
        while (ptr < segs.size() && segs[ptr].second >= pt.first) bit.add(segs[ptr].first, 1), ++ptr;
        ans[pt.second.second] += bit.qry(pt.first) - bit.qry(pt.second.first - 1);
    }
    for (int i = 0; i < m; ++i) cout << ans[i] << endl;
    return 0;
}