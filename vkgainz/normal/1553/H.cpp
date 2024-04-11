#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct node {
    vector<int> ans;
    vector<int> mn;
    vector<int> mx;
    node(int sz) {
        ans.resize(1 << sz, 1e9);
        mn.resize(1 << sz, 1e9);
        mx.resize(1 << sz, -1e9);
    }
};

node solve(vector<int> a, int d) { 
    node ret = node(d + 1);
    if (a.empty()) return ret; //check this base case
    if (d == 0) {
        for (int i = 0; i < 2; i++) {
            for (int x : a) {
                ret.mn[i] = min(ret.mn[i], (x ^ i));
                ret.mx[i] = max(ret.mx[i], (x ^ i));
            }
        }
        for (int i = 0; i < (int) a.size() - 1; i++) {
            ret.ans[0] = min(ret.ans[i], a[i + 1] - a[i]);
        }
        ret.ans[1] = ret.ans[0];
        return ret;
    }
    vector<int> l, r;
    for (int x : a) {
        if (x & (1 << d)) r.push_back(x ^ (1 << d));
        else l.push_back(x);
    }
    node x = solve(l, d - 1), y = solve(r, d - 1);
    for (int q = 0; q < (1 << (d + 1)); q++) {
        if (q & (1 << d)) {
            int r = x.mn[q ^ (1 << d)] + (1 << d), s = y.mx[q ^ (1 << d)];
            ret.ans[q] = min({ret.ans[q], r - s, x.ans[q ^ (1 << d)], y.ans[q ^ (1 << d)]});
            ret.mn[q] = min(x.mn[q ^ (1 << d)] + (1 << d), y.mn[q ^ (1 << d)]);
            ret.mx[q] = max(x.mx[q ^ (1 << d)] + (1 << d), y.mx[q ^ (1 << d)]);
        }
        else {
            int r = x.mx[q], s = y.mn[q] + (1 << d);
            ret.ans[q] = min({ret.ans[q], s - r, x.ans[q], y.ans[q]});
            ret.mn[q] = min(x.mn[q], y.mn[q] + (1 << d));
            ret.mx[q] = max(x.mx[q], y.mx[q] + (1 << d));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k; vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    node info = solve(a, k - 1);
    for (int ans : info.ans) {
        cout << ans << " ";
    }
    cout << "\n";
}