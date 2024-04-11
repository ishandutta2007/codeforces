#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <array>
#include <set>

using namespace std;

struct seg_tree {
    vector<long long> seg;
    int sz;
    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.resize(2 * sz, 4e18);
    }
    void upd(int i, long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] = min(seg[x], v);
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) upd(i, v, 2 * x + 1, lx, m);
        else upd(i, v, 2 * x + 2, m, rx);
        seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void upd(int i, long long v) { upd(i, v, 0, 0, sz); }
    long long query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 4e18;
        if (lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return min(query(l, r, 2 * x + 1, lx, m),
                query(l, r, 2 * x + 2, m, rx));
    }
    long long query(int l, int r) { return query(l, r, 0, 0, sz); }
};

int main() {
    int n, q; cin >> n >> q;
    vector<int> x(n), w(n);
    vector<int> nxt(n, n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> w[i];
    }
    vector<vector<pair<int, int>>> queries(n);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        --l, --r;
        queries[l].push_back({r, i});
    }
    set<pair<int, int>, greater<pair<int, int>>> work; //{w[idx], idx} in dec order
    set<int> keep;
    seg_tree vals;
    vals.init(n);
    vector<long long> ans(q);
    vector<int> stack;
    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty()) {
            if (w[stack.back()] > w[i]) {
                stack.pop_back();
            } else {
                break;
            }
        }
        if (!stack.empty()) nxt[i] = stack.back();
        stack.push_back(i);
        for (auto &it : keep) {
            if (it > nxt[i]) break;
            int j = it;
            vals.upd(j, (x[j] - x[i]) * 1LL * (w[i] + w[j]));
        }
        auto it = work.begin();
        while (it != work.end()) {
            if ((*it).first < w[i]) {
                break;
            }
            keep.erase((*it).second);
            work.erase(it++);
        }
        keep.insert(i);
        work.insert({w[i], i});
        for (auto &query : queries[i]) {
            int r = query.first;
            ans[query.second] = vals.query(0, r + 1);
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}