#include <bits/stdc++.h>
using namespace std;

#define rsz(x) x.clear(), x.resize(n)

struct seg_tree {
    vector<int> seg; //store min
    vector<int> lazy;
    int sz;
    void init(int n) {
        sz = 1;
        while(sz < n) sz *= 2;
        seg.resize(2 * sz);
        lazy.resize(2 * sz);
    }
    void push(int x, int lx, int rx, int v) {
        seg[x] += v;
        if(rx - lx != 1) {
            lazy[2 * x + 1] += v;
            lazy[2 * x + 2] += v;
        }
    }
    void prop(int x, int lx, int rx) {
        push(x, lx, rx, lazy[x]);
        lazy[x] = 0;
    }
    void upd(int l, int r, int v, int x, int lx, int rx) {
        prop(x, lx, rx);
        if(lx >= r || rx <= l) return;
        if(lx >= l && rx <= r) {
            push(x, lx, rx, v);
            return;
        }
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);
        seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void upd(int l, int r, int v) { upd(l, r, v, 0, 0, sz); }
    int query(int l, int r, int x, int lx, int rx) {
        prop(x, lx, rx);
        if(lx >= r || rx <= l) return 1e9;
        if(lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return min(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }
    int query(int l, int r) { return query(l, r, 0, 0, sz); }
} sto;

struct seg {
    int l, r, w;
};

bool cmp(seg &x, seg &y) {
    return x.w < y.w;
}

void ins(seg x) {
    sto.upd(x.l, x.r - 1, 1);
}

void del(seg x) {
    sto.upd(x.l, x.r - 1, -1);
}

int main() {
    int n, m; cin >> n >> m;
    vector<seg> in(n);
    sto.init(m);
    for(int i = 0; i < n; i++) {
        int l, r, w; cin >> l >> r >> w;
        --l;
        in[i] = {l, r, w};
    }
    sort(in.begin(), in.end(), cmp);

    int l = n - 1;
    int ans = 1e9;
    for(int r = n - 1; r >= 0; r--) {
        while(l >= 0 && (sto.query(0, m - 1) == 0)) {
            ins(in[l--]);
        }
        if(sto.query(0, m - 1) != 0) {
            int f = r, s = l + 1;
            ans = min(ans, in[f].w - in[s].w);
        }
        del(in[r]);
    }
    cout << ans << "\n";
}