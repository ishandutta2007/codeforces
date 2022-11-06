#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 25e4 + 10;
bool v[maxn], vis[maxn];

struct data {
    int m, r, p, d;
    data(int a, int b, int c, int d): m(a), r(b), p(c), d(d) {}
    bool operator<(const data& rhs) const {
        return d < rhs.d;
    }
};

vector<data> dt;

struct fenwick {
    vector<deque<int>> arr;
    int n;
    void init(int _n) {
        n = _n;
        arr.resize((size_t)n);
    }
    inline int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        for (int i = x; i < n; i += lowbit(i)) arr[i].push_back(v);
    }
    deque<int> qry(int x, int d) {
        deque<int> ret;
        for (int i = x; i; i -= lowbit(i)) {
            while (arr[i].size() && dt[arr[i].front()].d <= d) {
                if (!v[arr[i].front()]) ret.push_back(arr[i].front());
                v[arr[i].front()] = true;
                arr[i].pop_front();
            }
        }
        return ret;
    }
} bit;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x, y, p, r, n; cin >> x >> y >> p >> r >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int xi, yi, m, p, r; cin >> xi >> yi >> m >> p >> r;
        int dis = (x - xi) * (x - xi) + (y - yi) * (y - yi);
        dt.push_back(data(m, r * r, p, dis));
        v.push_back(m); v.push_back(p);
    }
    dt.push_back(data(0, r * r, p, 0)); v.push_back(0); v.push_back(p);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    for (data& i : dt) {
        i.m = lower_bound(v.begin(), v.end(), i.m) - v.begin() + 1;
        i.p = lower_bound(v.begin(), v.end(), i.p) - v.begin() + 1;
    }
    sort(dt.begin(), dt.end());
    bit.init(v.size() + 1);
    for (int i = 0; i < dt.size(); ++i) bit.add(dt[i].m, i);
    queue<int> que; que.push(0);
    int ans = 0;
    while (que.size()) {
        int t = que.front(); que.pop();
        if (vis[t]) continue;
        vis[t] = true; ++ans;
        deque<int> res = bit.qry(dt[t].p, dt[t].r);
        for (int i : res) que.push(i);
    }
    cout << ans - 1 << endl;
    return 0;
}