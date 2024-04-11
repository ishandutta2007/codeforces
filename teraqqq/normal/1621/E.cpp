#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5+7;

struct SegmentTree {
    int n;
    vector<int> tadd, tmin;

    SegmentTree(int n) : n(n), tadd(4*n), tmin(4*n) { }

    void add(int v, int vl, int vr, int l, int r, int x) {
        if (l <= vl && vr <= r) {
            tadd[v] += x;
            tmin[v] += x;
        } else if (r <= vl || vr <= l) {
            // nope :)
        } else {
            int vm = (vl + vr) / 2;
            add(2*v, vl, vm, l, r, x);
            add(2*v+1, vm, vr, l, r, x);
            tmin[v] = min(tmin[2*v], tmin[2*v+1]) + tadd[v];
        }
    }

    int global_min() {
        return tmin[1];
    }

    void add(int l, int r, int x) {
        add(1, 0, n, l, r, x);
    }
} sgt(N);

void solve() {
    int n, m; cin >> n >> m;

    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
        sgt.add(0, x, 1);
    }

    vector<int> k(m);
    int sum_size = 0;
    vector<vector<int>> b(m);
    vector<ll> sumb(m);

    auto  cost = [&] (int i) {
        return (sumb[i] + k[i] - 1) / k[i];
    };

    for (int i = 0; i < m; ++i) {
        auto& v = b[i];
        cin >> k[i]; sum_size += k[i];
        v.resize(k[i]);
        for (int& x : v) cin >> x, sumb[i] += x;

        sgt.add(0, cost(i), -1);
    }

    vector<int> ans;

    for (int i = 0; i < m; ++i) {
        for (int x : b[i]) {
            sgt.add(0, cost(i), +1);
            sumb[i] -= x;
            k[i]--;
            sgt.add(0, cost(i), -1);
            ans.push_back(sgt.global_min() < 0 ? 0 : 1);
            sgt.add(0, cost(i), +1);
            k[i]++;
            sumb[i] += x;

            sgt.add(0, cost(i), -1);
        }
    }

    for (int x : ans) cout << x;
    cout << '\n';

    for (int x : a) sgt.add(0, x, -1);
    for (int i = 0; i < m; ++i) {
        sgt.add(0, cost(i), +1);
    }

    // cout << sgt.global_min() << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}