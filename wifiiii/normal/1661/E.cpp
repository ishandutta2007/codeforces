#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int par[12], pp[12];
int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}
struct segtree {
    struct node {
        int l[3], r[3], par[6], cnt = -1;
        int find(int x) {
            return x == par[x] ? x : par[x] = find(par[x]);
        }
        void merge(int u, int v) {
            int x = find(u), y = find(v);
            par[x] = y;
        }
    };
    node merge(const node &x, const node &y) {
        if(x.cnt == -1) return y;
        if(y.cnt == -1) return x;
        node ret;
        for(int i = 0; i < 3; ++i) {
            ret.l[i] = x.l[i];
            ret.r[i] = y.r[i];
        }
        ret.cnt = x.cnt + y.cnt;
        for(int i = 0; i < 6; ++i) {
            par[i] = x.par[i];
            par[i + 6] = y.par[i] + 6;
        }
        for(int i = 0; i < 3; ++i) {
            if(x.r[i] && y.l[i]) {
                int x = find(par[i + 3]), y = find(par[i + 6]);
                if(x != y) {
                    par[y] = x;
                    ret.cnt--;
                }
            }
        }
        for(int i = 0; i < 3; ++i) pp[find(i)] = i;
        for(int i = 9; i < 12; ++i) pp[find(i)] = i - 6;
        for(int i = 0; i < 3; ++i) ret.par[i] = pp[find(i)];
        for(int i = 9; i < 12; ++i) ret.par[i - 6] = pp[find(i)];
        return ret;
    }
    void build(int l, int r, int rt, const vector<string> &v) {
        if(l == r) {
            int cnt = 0;
            for(int i = 0; i < 6; ++i) a[rt].par[i] = i;
            for(int i = 0; i < 3; ++i) {
                a[rt].l[i] = a[rt].r[i] = v[i][l] - '0';
                cnt += a[rt].l[i];
                a[rt].merge(i, i + 3);
            }
            for(int i = 0; i < 2; ++i) {
                if(a[rt].l[i] && a[rt].l[i + 1]) {
                    cnt -= 1;
                    a[rt].merge(i, i + 1);
                }
            }
            a[rt].cnt = cnt;
            return;
        }
        int m = (l + r) / 2;
        build(l, m, rt << 1, v);
        build(m + 1, r, rt << 1 | 1, v);
        a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
    }
    segtree(const vector<string> &v):n(v[0].size()), a(v[0].size() << 2) {
        build(0, n - 1, 1, v);
    }
    int n;
    vector<node> a;
    node query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) return a[rt];
        node ret;
        int m = (l + r) / 2;
        if(L <= m) ret = merge(ret, query(L, R, l, m, rt << 1));
        if(m < R) ret = merge(ret, query(L, R, m+1, r, rt << 1 | 1));
        return ret;
    }
    node qry(int L, int R) {
        return query(L, R, 0, n - 1, 1);
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<string> a(3);
    for(int i = 0; i < 3; ++i) cin >> a[i];
    segtree st(a);
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << st.qry(l, r).cnt << '\n';
    }
}