#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

#define hash hash_

// ---

constexpr int MOD = 1e9+7;
constexpr int BASE = 1e5+19;

mt19937 rnd(int(chrono::steady_clock::now().time_since_epoch().count()));

struct Node;
using pnode = shared_ptr<Node>;

struct Node {
    pnode left{0}, right{0};
    uint32_t weight{rnd()};
    int size{1}, value{0}, hash{0};
};

Vi mults;

void clone(pnode& x) {
    if (x && x.use_count() > 1) {
        x = make_shared<Node>(*x);
    }
}

int size(Node *x) {
    return x ? x->size : 0;
}

int hash(Node *x) {
    return x ? x->hash : 0;
}

void update(Node *x) {
    if (x) {
        Node *l = x->left.get(), *r = x->right.get();
        x->size = x->hash = 0;

        if (l) {
            x->hash = l->hash;
            x->size = l->size;
        }

        x->hash = int((x->hash + ll(x->value) * mults[x->size]) % MOD);
        x->size++;

        if (r) {
            x->hash = int((x->hash + ll(r->hash) * mults[x->size]) % MOD);
            x->size += r->size;
        }
    }
}

void split(pnode x, pnode& l, pnode& r, int i) {
    l = r = 0;
    if (!x) return;

    int key = size(x->left.get());
    clone(x);

    if (i <= key) {
        split(move(x->left), l, x->left, i);
        r = x;
    } else {
        split(move(x->right), x->right, r, i-key-1);
        l = x;
    }

    update(x.get());
}

pnode join(pnode l, pnode r) {
    if (!l) return r;
    if (!r) return l;

    if (l->weight < r->weight) {
        clone(l);
        l->right = join(move(l->right), move(r));
        update(l.get());
        return l;
    }

    clone(r);
    r->left = join(move(l), move(r->left));
    update(r.get());
    return r;
}

// ---

struct Elem {
    pnode x, y;
    bool valid;
};

Elem merge(Elem a, Elem b) {
    if (!a.valid || !b.valid) {
        return {0,0,0};
    }

    int sl = size(a.y.get()), sr = size(b.x.get());

    if (sl < sr) {
        pnode low, high;
        split(move(b.x), low, high, sr-sl);
        if (hash(a.y.get()) == hash(high.get())) {
            return {join(move(low), move(a.x)), move(b.y), 1};
        }
    } else if (sl > sr) {
        pnode low, high;
        split(move(a.y), low, high, sl-sr);
        if (hash(high.get()) == hash(b.x.get())) {
            return {move(a.x), join(move(low), move(b.y)), 1};
        }
    } else {
        if (hash(a.y.get()) == hash(b.x.get())) {
            return {move(a.x), move(b.y), 1};
        }
    }

    return {0,0,0};
}

Elem make(int t) {
    pnode x = make_shared<Node>();
    x->value = x->hash = abs(t);
    return t > 0 ? Elem{0, x, 1} : Elem{x, 0, 1};
}

// ---

vector<Elem> tree;
int len;

void change(int i, Elem val) {
    i += len;
    tree[i] = val;
    while (i /= 2) {
        tree[i] = merge(tree[i*2], tree[i*2+1]);
    }
}

Elem query(int b, int e) {
    b += len; e += len-1;
    if (b > e) return {0,0,1};
    if (b == e) return tree[b];

    Elem pref = tree[b], suf = tree[e];

    while (b/2 < e/2) {
        if (~b&1) pref = merge(pref, tree[b^1]);
        if (e&1) suf = merge(tree[e^1], suf);
        b /= 2; e /= 2;
    }

    return merge(pref, suf);
}

void run() {
    int n, k;
    cin >> n >> k;

    mults.resize(n+5, 1);
    rep(i, 1, sz(mults)) {
        mults[i] = int(ll(mults[i-1]) * BASE % MOD);
    }

    len = 1;
    while (len < n) len *= 2;
    tree.resize(len*2, {0, 0, 1});

    rep(i, 0, n) {
        int t; cin >> t;
        tree[i+len] = make(t);
    }

    for (int i = len-1; i > 0; i--) {
        tree[i] = merge(tree[i*2], tree[i*2+1]);
    }

    int q; cin >> q;

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            change(b-1, make(c));
        } else if (a == 2) {
            Elem p = query(b-1, c);
            bool ans = (!p.x && !p.y && p.valid);
            cout << (ans ? "Yes\n" : "No\n");
        } else {
            assert(0);
        }
    }
}