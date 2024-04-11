#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

struct SegmentTree {
    int n;
    vector<int> tadd, tmax;

    SegmentTree(int n) : n(n), tadd(4*n), tmax(4*n) { }

    void add(int v, int vl, int vr, int l, int r, int x) {
        if (l <= vl && vr <= r) {
            tadd[v] += x;
            tmax[v] += x;
        } else if (vl < r && l < vr) {
            int vm = (vl + vr) / 2;
            add(2*v, vl, vm, l, r, x);
            add(2*v+1, vm, vr, l, r, x);
            tmax[v] = ::max(tmax[2*v], tmax[2*v+1]) + tadd[v];
        }
    }

    void add(int l, int r, int x) {
        add(1, 0, n, l, r, x);
    }

    int max(int v, int vl, int vr, int l, int r) {
        if (l <= vl && vr <= r) return tmax[v];
        if (r <= vl || vr <= l) return 0;
        int vm = (vl + vr) / 2;
        return tadd[v] + ::max(max(2*v, vl, vm, l, r), max(2*v+1, vm, vr, l, r));
    }

    int max(int l, int r) {
        return max(1, 0, n, l, r);
    }
};

struct Query {
    int l, r, w;
};

void solve() {
    int n; cin >> n;
    vector<int> h(n);
    for (int& x : h) cin >> x;

    int m; cin >> m;
    vector<Query> q(m);
    for (auto& [l, r, w] : q) cin >> l >> r >> w, --l;

    vector<int> cl(m, -1), cr(m, n-1);

    vector<int> p(n); iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int l, int r) { return h[l] > h[r]; });

    while (true) {
        vector<vi> ask(n);
        vi pl(n), pr(n);
        SegmentTree sgt(n);
        vector<char> used(n);
        iota(pl.begin(), pl.end(), 0);
        iota(pr.begin(), pr.end(), 0);
        bool any = false;
        for (int i = 0; i < m; ++i) {
            if (cl[i] + 1 != cr[i]) ask[(cl[i] + cr[i]) / 2].push_back(i), any = true;
        }
        if (!any) break;

        int pos = 0;
        for (int i : p) {
            used[i] = true;
            sgt.add(i, i+1, 1);
            if (i > 0 && used[i-1]) {
                sgt.add(pl[i-1], i, +1);
                pl[i] = pl[i-1];
            }
            if (i < n - 1 && used[i+1]) {
                sgt.add(pl[i], i+1, pr[i+1] - i);
                pr[i] = pr[i+1];
            }
            pr[pl[i]] = pr[i];
            pl[pr[i]] = pl[i];

            for (int j : ask[pos]) {
                int d = sgt.max(q[j].l, q[j].r+1-q[j].w);
                if (d < q[j].w) cl[j] = pos;
                else cr[j] = pos;   
            }

            ++pos;
        }
    }

    for (int i : cr) cout << h[p[i]] << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t; 
    while(t--) solve();
}