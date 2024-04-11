#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 10;

int n, q;
struct Node{
    ll pre, suf, full, sz, tot;

} st[2 * MN];

Node merge(Node l, Node r){
    if (l.sz == 0) return r;
    if (r.sz == 0) return l;
    Node ret;
    if (l.full) ret.pre = l.sz + r.pre;
    else ret.pre = l.pre;
    if (r.full) ret.suf = r.sz + l.suf;
    else ret.suf = r.suf;
    if (l.full && r.full) ret.full = 1;
    else ret.full = 0;
    ret.sz = l.sz + r.sz;
    ret.tot = l.tot + r.tot;
    ret.tot += l.suf * (r.pre + (!r.full));
    return ret;
}

void ins(int i, int val, int v = 1, int l = 1, int r = n){
    if (l == r) st[v] = {val, val, val, 1, 1};
    else{
        if (i <= mid) ins(i, val, lc, l, mid);
        else ins(i, val, rc, mid + 1, r);
        st[v] = merge(st[lc], st[rc]);
    }
}

Node query(int ql, int qr, int v = 1, int l = 1, int r = n){
    if (l > qr || r < ql) return {-1, 0, 1, 0, 0};
    if (l >= ql && r <= qr) return st[v];
    else{
        Node ret = merge(query(ql, qr, lc, l, mid), query(ql, qr, rc, mid + 1, r));
        // cout << l << " " << r << " -> " << ret.tot << '\n';
        return ret;
    }
}

int a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i){
        ins(i, a[i] <= a[i + 1]);
    }
    while (q--){
        int op; cin >> op;
        if (op == 1){
            int i, v; cin >> i >> v;
            a[i] = v;
            if (i != 1) ins(i - 1, a[i - 1] <= a[i]);
            if (i != n) ins(i, a[i] <= a[i + 1]);
        }
        if (op == 2){
            int l, r; cin >> l >> r;
            cout << query(l, r).tot << '\n';
        }
    }
}