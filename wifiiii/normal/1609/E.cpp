#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> p {0,1,2,3,4,5,6,7,11,15,22,23,31};
int nxt[32][32];
struct segtree {
    struct node {
        int mx[32];
        node() {
            for(int i = 0; i < 32; ++i) mx[i] = -1;
        }
        void upd(int l, int r, char c) {
            mx[0] = mx[1] = mx[2] = mx[4] = 0;
            if(c == 'a') mx[1] = 1;
            if(c == 'b') mx[2] = 1;
            if(c == 'c') mx[4] = 1;
        }
    };
    node merge(const node &x, const node &y) {
        if(x.mx[0] == -1) return y;
        if(y.mx[0] == -1) return x;
        node ret;
        for(int i : p) {
            if(x.mx[i] != -1) {
                for(int j : p) {
                    if(y.mx[j] != -1 && nxt[i][j] != -1) {
                        ret.mx[nxt[i][j]] = max(ret.mx[nxt[i][j]], x.mx[i] + y.mx[j]);
                    }
                }
            }
        }
        return ret;
    }
    void pushdown(int l, int r, int rt) {

    }
    void build(int l, int r, int rt) {
        if(l == r) {
            return;
        }
        int m = (l + r) / 2;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
    }
    void build(int l, int r, int rt, const string &v) {
        if(l == r) {
            a[rt].mx[0] = 0;
            char c = v[l];
            if(c == 'a') a[rt].mx[1] = 1;
            if(c == 'b') a[rt].mx[2] = 1;
            if(c == 'c') a[rt].mx[4] = 1;
            return;
        }
        int m = (l + r) / 2;
        build(l, m, rt << 1, v);
        build(m + 1, r, rt << 1 | 1, v);
        a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
    }
    segtree(int n):n(n), a(n << 2) {
        build(0, n - 1, 1);
    }
    segtree(const string &v):n(v.size()), a(v.size() << 2) {
        build(0, n - 1, 1, v);
    }

    int n;
    vector<node> a;
    template <typename... V>
    void update(int L, int R, int l, int r, int rt, const V&... v) {
        if(L <= l && r <= R) {
            a[rt].upd(l, r, v...);
            return;
        }
        pushdown(l, r, rt);
        int m = (l + r) / 2;
        if(L <= m) update(L, R, l, m, rt << 1, v...);
        if(m < R) update(L, R, m+1, r, rt << 1 | 1, v...);
        a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
    }
    template <typename... V>
    void upd(int L, int R, const V&... v) {
        update(L, R, 0, n - 1, 1, v...);
    }
    node query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) return a[rt];
        node ret;
        pushdown(l, r, rt);
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
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i : p) {
        int a1 = i >> 0 & 1;
        int b1 = i >> 1 & 1;
        int c1 = i >> 2 & 1;
        int ab1 = i >> 3 & 1;
        int bc1 = i >> 4 & 1;
        for(int j : p) {
            int a2 = j >> 0 & 1;
            int b2 = j >> 1 & 1;
            int c2 = j >> 2 & 1;
            int ab2 = j >> 3 & 1;
            int bc2 = j >> 4 & 1;
            int a3 = 0, b3 = 0, c3 = 0, ab3 = 0, bc3 = 0, ok = 1;
            if(a1 || a2) a3 = 1;
            if(b1 || b2) b3 = 1;
            if(c1 || c2) c3 = 1;
            if(ab1 || ab2 || (a1 && b2)) ab3 = 1;
            if(bc1 || bc2 || (b1 && c2)) bc3 = 1;
            if((ab1 && c2) || (a1 && bc2)) ok = 0;
            int res = (a3) + (b3<<1) + (c3<<2) + (ab3<<3) + (bc3<<4);
            if(ok) {
                nxt[i][j] = res;
            } else {
                nxt[i][j] = -1;
            }
        }
    }
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    segtree st(s);
    while(q--) {
        int p; char c;
        cin >> p >> c;
        p -= 1;
        st.upd(p, p, c);
        auto ans = st.qry(0, n - 1);
        int mx = 0;
        for(int i = 0; i < 32; ++i) {
            mx = max(mx, ans.mx[i]);
        }
        cout << n - mx << '\n';
    }
}