#include <bits/stdc++.h>

using ll = long long;
#define int ll
using namespace std;
struct edge {
    int next, w;
};
template<typename T>
using pqg = priority_queue<T, vector<T>, greater<>>;

struct SumTree {
    int n;
    vector<int> data;

    SumTree(int n) : n(n), data(2 * n) {}

    void add(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) data[l++]++;
            if (r & 1) data[--r]++;
        }
    }

    int get(int i) {
        int res = 0;
        for (i += n; i > 0; i /= 2) res += data[i];
        return res;
    }
};

int32_t main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> s(n);
    vector<int> len(n);
    for (auto &[l, r]: s) cin >> l >> r;
    for (auto &[l, r]: s) --l;
    for (int i = 0; i < n; ++i) len[i] = s[i].second - s[i].first;
    vector<int> ans(30);
    vector<pair<int, int *>> vals;
    for (int i = 0; i < n; ++i) {
        vals.emplace_back(s[i].first, &s[i].first);
        vals.emplace_back(s[i].second, &s[i].second);
    }
    sort(vals.begin(), vals.end(), [](auto p, auto q) { return p.first < q.first; });
    for (int k = 29; k >= 0; --k) {
        vector<pair<int, int *>> l, r;
        l.reserve(2 * n);
        r.reserve(2 * n);
        const int mod = 1 << k;
        for (auto[x, p]: vals) {
            (x < mod ? l : r).emplace_back(x % mod, p);
        }
        merge(l.begin(), l.end(), r.begin(), r.end(), vals.begin(), [](auto p, auto q) { return p.first < q.first; });
        int cur = 0;
        for (int i = 0; i < 2 * n; ++i) {
            if (i != 0 && vals[i].first != vals[i - 1].first) cur++;
            *vals[i].second = cur;
        }
        for (int i = 0; i < n; ++i) {
            if (len[i] >= mod) s[i].second = s[i].first;
        }
        vector<int> p(vals.size() + 1);
        for (auto[l, r]: s) {
            if (l < r) {
                p[l]++;
                p[r]--;
            } else {
                p[l]++;
                p[vals.size()]--;
                p[0]++;
                p[r]--;
            }
        }
        for (int i = 1; i <= vals.size(); ++i) p[i] += p[i - 1];
        for (int i = 0; i < vals.size(); ++i) ans[k] = max(ans[k], p[i]);
    }
    int q;
    cin >> q;
    for (int j = 0; j < q; ++j) {
        int w;
        cin >> w;
        int a = __builtin_ctz(w);
        cout << ans[a] << '\n';

    }
}