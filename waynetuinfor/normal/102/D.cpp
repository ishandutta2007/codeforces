#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
pair<int, int> p[maxn];
int dp[maxn];

int ad(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sb(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b) { return (long long)a * (long long)b % mod; }

struct Fenwick {
    int n;
    vector<int> arr;
    void init(int _n) {
        n = _n;
        arr.resize(n);
    }
    inline int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        for (int i = x; i < n; i += lowbit(i)) arr[i] = ad(arr[i], v);
    }
    int qry(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret = ad(ret, arr[i]);
        return ret;
    }
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < m; ++i) {
        cin >> p[i].first >> p[i].second;
        v.emplace_back(p[i].first); v.emplace_back(p[i].second);
    }
    v.emplace_back(0); v.emplace_back(n);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    bit.init((int)v.size() + 10);
    sort(p, p + m, [](const pair<int, int>& a, const pair<int, int>& b) { return a.second == b.second ? a.first < b.first : a.second < b.second; });
    bit.add(1, 1);
    for (int i = 0; i < m; ) {
        int tmp = i;
        while (i < m && p[i] == p[tmp]) ++i;
        int l = lower_bound(v.begin(), v.end(), p[tmp].first) - v.begin() + 1, r = lower_bound(v.begin(), v.end(), p[tmp].second) - v.begin() + 1;
        dp[i - 1] = mul(i - tmp, sb(bit.qry(r - 1), bit.qry(l - 1)));
        bit.add(r, dp[i - 1]);
    }
    cout << sb(bit.qry(v.size()), bit.qry(v.size() - 1)) << endl;
    return 0;
}