#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

struct Query {
    int l, r, x;
};

struct SegmentTree {
    int n;
    vector<int> t;

    SegmentTree(int n) : n(n), t(4*n) { build(1, 0, n); }

    void build(int v, int vl, int vr) {
        t[v] = vr - vl;
        if (vl + 1 != vr) {
            int vm = (vl + vr) / 2;
            build(2*v, vl, vm);
            build(2*v+1, vm, vr);
        }
    }
    
    int sum(int v, int vl, int vr, int l, int r) {
        if (t[v] == 0) return 0;
        if (l <= vl && vr <= r) return t[v];
        if (r <= vl || vr <= l) return 0;

        int vm = (vl + vr) / 2;
        return sum(2*v, vl, vm, l, r) + sum(2*v+1, vm, vr, l, r);
    }

    void clear(int v, int vl, int vr, int l, int r) {
        if (t[v] == 0) return;
        if (l <= vl && vr <= r) {
            t[v] = 0;
        } else if (r <= vl || vr <= l) {
            // nope :D
        } else {
            int vm = (vl + vr) / 2;
            clear(2*v, vl, vm, l, r);
            clear(2*v+1, vm, vr, l, r);
            t[v] = t[2*v] + t[2*v+1];
        }
    }

    int sum(int l, int r) { 
        int res = sum(1, 0, n, l, r);
        // cout << "[" << l << ", " << r << ") ==> sum = " << res << '\n';
        return res; 
    }
    void clear(int l, int r) { 
        // cout << "clear [" << l << ", " << r << ")" << '\n';
        clear(1, 0, n, l, r); 
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> val(n, 1), time(n, q);
    vector<Query> msg(q);
    for (auto& [l, r, x] : msg) {
        int t; cin >> t;
        if (t == 0) {
            cin >> l >> r >> x; --l;
        } else {
            cin >> l; --l;
            r = x = -1;
        }
    }

    vector<int> bsl(q), bsr(q);

    for (int i = 0; i < q; ++i) {
        if (msg[i].x == 1) {
            bsl[i] = 0;
            bsr[i] = q;
        } else {
            bsl[i] = -1;
            bsr[i] = 0;
        }
    }

    while (true) {
        vector<vi> lst(q);
        bool any = false;
        for (int i = 0; i < q; ++i) {
            if (bsl[i] + 1 != bsr[i]) lst[(bsl[i] + bsr[i]) / 2].push_back(i), any = true;
        }

        if (!any) break;
        
        SegmentTree sgt(n);
        for (int i = 0; i < q; ++i) {
            for (int j : lst[i]) {
                if (sgt.sum(msg[j].l, msg[j].r) == 1) {
                    bsr[j] = i;
                } else {
                    bsl[j] = i;
                }
            }

            if (msg[i].x == 0) {
                sgt.clear(msg[i].l, msg[i].r);
            }
        }
    }

    vector<vi> ptr(q);
    for (int i = 0; i < q; ++i) {
        if (msg[i].x == 1) ptr[bsl[i]].push_back(i);
    }

    set<int> alive;
    for (int i = 0; i <= n; ++i) alive.insert(i);

    for (int i = 0; i < q; ++i) {
        if (msg[i].x == 0) {
            auto it = alive.lower_bound(msg[i].l);
            while (*it < msg[i].r) {
                const int j = *(it++);
                val[j] = 0;
                time[j] = i;
                alive.erase(j);
            }
        }

        for (int j : ptr[i]) {
            const int t = *alive.lower_bound(msg[j].l);
            ckmin(time[t], max(j, bsl[j]));
        }
    }

    for (int i = 0; i < q; ++i) {
        if (msg[i].x == -1) {
            const int j = msg[i].l;
            if (i > time[j]) {
                cout << (val[j] ? "YES" : "NO") << '\n';
            } else {
                cout << "N/A" << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    // cin >> t;
    while (t--) solve();
}