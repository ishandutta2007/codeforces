#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<pair<int, int>> p(q);
    for (int i = 0; i < q; i++) {
        cin >> p[i].first >> p[i].second;
        p[i].first--;
    }
    vector<int> ans(q);
    vector<int> c(n);
    vector<int> cx(q);
    vector<int> cy(q);
    vector<int> bx(q);
    vector<int> by(q);
    function<void(int, int, vector<int>)> dfs = [&](int l, int r, vector<int> v) {
        if (l + 1 == r) {
            for (int i : v) {
                ans[i] = 1;
            }
            return;
        }
        int mid = (l + r) / 2;
        vector<int> vl, vr;
        vector<int> maxa(r - l);
        vector<int> maxc(r - l);
        int mxc = 0;
        int mxa = -1;
        for (int i = mid; i < r; i++) {
            c[a[i]]++;
            if (c[a[i]] > mxc) {
                mxc = c[a[i]];
                mxa = a[i];
            }
            maxa[i - l] = mxa;
            maxc[i - l] = mxc;
        }
        for (int i = mid; i < r; i++) {
            c[a[i]]--;
        }
        mxc = 0, mxa = -1;
        for (int i = mid - 1; i >= l; i--) {
            c[a[i]]++;
            if (c[a[i]] > mxc) {
                mxc = c[a[i]];
                mxa = a[i];
            }
            maxa[i - l] = mxa;
            maxc[i - l] = mxc;
        }
        for (int i = mid - 1; i >= l; i--) {
            c[a[i]]--;
        }
        vector<vector<int>> g(r - l);
        vector<int> f;
        for (int i : v) {
            if (mid <= p[i].first) {
                vr.emplace_back(i);
                continue;
            } else if (p[i].second <= mid) {
                vl.emplace_back(i);
                continue;
            }
            cx[i] = maxa[p[i].first - l];
            cy[i] = maxa[p[i].second - 1 - l];
            g[p[i].first - l].emplace_back(i);
            g[p[i].second - 1 - l].emplace_back(i);
            f.emplace_back(i);
        }
        for (int i = mid; i < r; i++) {
            c[a[i]]++;
            for (int j : g[i - l]) {
                bx[j] += c[cx[j]];
                by[j] += c[cy[j]];
            }
        }
        for (int i = mid; i < r; i++) {
            c[a[i]]--;
        }
        for (int i = mid - 1; i >= l; i--) {
            c[a[i]]++;
            for (int j : g[i - l]) {
                bx[j] += c[cx[j]];
                by[j] += c[cy[j]];
            }
        }
        for (int i = mid - 1; i >= l; i--) {
            c[a[i]]--;
        }
        for (int i : f) {
            int s = max(bx[i], by[i]);
            int len = p[i].second - p[i].first;
            if ((len + 1) / 2 >= s) {
                ans[i] = 1;
                continue;
            }
            int t = len - s;
            ans[i] = s - t;
        }
        if (!vl.empty()) {
            dfs(l, mid, vl);
        }
        if (!vr.empty()) {
            dfs(mid, r, vr);
        }
    };
    vector<int> v(q);
    iota(v.begin(), v.end(), 0);
    dfs(0, n, v);
    for (int i : ans) {
        cout << i << '\n';
    }
    debug(bx, by);
    return 0;
}