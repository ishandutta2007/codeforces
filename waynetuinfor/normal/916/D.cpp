#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, memsize = 4e7 + 10, inf = 1e9;
map<string, int> mp;

struct segtree {
    segtree *lc, *rc;
    int val;
    void pull() { val = (lc ? lc->val : 0) + (rc ? rc->val : 0); }
    segtree(): val(0), lc(nullptr), rc(nullptr) {}
    segtree(segtree *t): val(t->val), lc(t->lc), rc(t->rc) {}
    segtree *modify(int, int, int, int);
    int query(int, int, int, int);
} *tpri[maxn], *tmap[maxn];

struct {
    union uni {
        uni *nxt;
        segtree sgt;
        uni(): nxt(this + 1) {}
        ~uni() {}
    } dat[memsize];
    uni *head = dat;
    segtree *allocate() {
        uni *now = head;
        head = head->nxt;
        return &now->sgt;
    }
    void deallocate(segtree *t) {
        uni *now = reinterpret_cast<uni*>(t);
        now->nxt = head;
        head = now;
    }
} _allocator;

segtree *segtree::modify(int l, int r, int p, int v) {
    segtree *sgt = new (_allocator.allocate()) segtree(this);
    if (l == r) return sgt->val += v, sgt;
    int m = (l + r) >> 1;
    if (p <= m && !lc) lc = new (_allocator.allocate()) segtree();
    else if (p > m && !rc) rc = new (_allocator.allocate()) segtree();
    if (p <= m) sgt->lc = lc->modify(l, m, p, v);
    else sgt->rc = rc->modify(m + 1, r, p, v);
    sgt->pull();
    return sgt;
}

int segtree::query(int l, int r, int ql, int qr) {
    if (l > qr || ql > r) return 0;
    if (l >= ql && r <= qr) return val;
    int m = (l + r) >> 1;
    return (lc ? lc->query(l, m, ql, qr) : 0) + (rc ? rc->query(m + 1, r, ql, qr) : 0);
}

int getid(string s) {
    if (mp.find(s) != mp.end()) return mp[s];
    return mp[s] = (int)mp.size();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int ptr = 0;
    tpri[0] = new (_allocator.allocate()) segtree(); tmap[0] = new (_allocator.allocate()) segtree();
    int q; cin >> q; while (q--) {
        string s; cin >> s;
        if (s == "set") {
            ++ptr;
            string a; int x; cin >> a >> x;
            int pos = getid(a), prv = ptr - 1, tmp;
            if ((tmp = tmap[prv]->query(1, maxn, pos, pos))) {
                tmap[ptr] = tmap[prv]->modify(1, maxn, pos, -tmp);
                tpri[ptr] = tpri[prv]->modify(1, inf, tmp, -1);
                prv = ptr;
            }
            tmap[ptr] = tmap[prv]->modify(1, maxn, pos, x);
            tpri[ptr] = tpri[prv]->modify(1, inf, x, 1);
        }
        if (s == "remove") {
            ++ptr;
            string a; cin >> a;
            int pos = getid(a), tmp;
            if ((tmp = tmap[ptr - 1]->query(1, maxn, pos, pos)) == 0) { 
                tmap[ptr] = tmap[ptr - 1]; tpri[ptr] = tpri[ptr - 1];
                continue;
            }
            tmap[ptr] = tmap[ptr - 1]->modify(1, maxn, pos, -tmp);
            tpri[ptr] = tpri[ptr - 1]->modify(1, inf, tmp, -1);
        }
        if (s == "query") {
            ++ptr;
            tmap[ptr] = tmap[ptr - 1]; tpri[ptr] = tpri[ptr - 1];
            string a; cin >> a;
            int pos = getid(a), tmp;
            if ((tmp = tmap[ptr]->query(1, maxn, pos, pos)) == 0) {
                cout << "-1" << endl;
                continue;
            }
            cout << tpri[ptr]->query(1, inf, 1, tmp - 1) << endl;
        }
        if (s == "undo") {
            int d; cin >> d;
            ++ptr;
            tpri[ptr] = tpri[ptr - d - 1];
            tmap[ptr] = tmap[ptr - d - 1];
        }
    }
    return 0;
}