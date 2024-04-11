#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    mutable int l, r, c;
    mutable ll v;
    bool operator < (const node & n) const {
        return l < n.l;
    }
};
set<node> s;
int n, q;
set<node>::iterator split(int x) {
     if(x == n) return s.end();
    auto it = --s.upper_bound({x});
    if(it->l == x) return it;
    node p = *it;
    it->r = x - 1, p.l = x;
    return s.insert(p).first;
}

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n) {}
    void add(int x, T v) {
        assert(0 <= x && x < n);
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] += v;
    }
    void add(int l, int r, T v) {
        add(l, v);
        if(r + 1 < n) add(r + 1, -v);
    }
    T qry(int x) {
        T ret = 0;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[i - 1];
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<ll> add(n);
    s.insert({0, n - 1, 0, 0});
    fenwick<ll> fen(n);
    while(q--) {
        string op;
        cin >> op;
        if(op[0] == 'C') {
            int l, r, c;
            cin >> l >> r >> c;
            --l, --r, --c;
            split(r + 1); auto it = split(l);
            fen.add(it->l, it->r, add[it->c] - it->v);
            it->c = c, it->v = add[c];
            while(it->r != r) {
                it = s.erase(it);
                fen.add(it->l, it->r, add[it->c] - it->v);
                it->c = c, it->v = add[c];
            }
            it->l = l;
        } else if(op[0] == 'A') {
            int c, x;
            cin >> c >> x;
            --c;
            add[c] += x;
        } else {
            int x;
            cin >> x;
            --x;
            split(x + 1); auto it = split(x);
            fen.add(it->l, it->r, add[it->c] - it->v);
            it->v = add[it->c];
            cout << fen.qry(x) << '\n';
        }
    }
}