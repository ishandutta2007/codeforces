#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

struct trie {
    int ands, ors, xors, full;
    int sub, len;
    trie *to[2];

    trie(int x, int y) {
        ands = ors = xors = full = 0;
        to[0] = to[1] = nullptr;
        sub = x, len = y;
    }

    void apply(int x, int y, int z) {
        if (((x & (len / 2)) > 0 && to[1]) || ((y & (len / 2)) > 0 && to[0])) {
            swap(to[0], to[1]);
        }

        if ((z & (len / 2)) > 0) {
            swap(to[0], to[1]);
        }

        ands |= x;
        ors &= ~x;
        xors &= ~x;

        ors |= y;
        ands &= ~y;
        xors &= ~y;

        xors ^= z;
    }

    void push() {
        for (auto c : to) {
            if (c) {
                c->apply(ands, ors, xors);
            }
        }
        ands = ors = xors = 0;
    }

    void pull() {
        sub = 0, full = 0;
        for (auto c : to) {
            if (c) {
                full |= c->full;
                sub += c->sub;
            }
        }

        if (to[0] && to[1]) {
            full |= len / 2;
        }
    }
};

int query(trie *u, int a, int b, int l) {
    if (!u || b <= l || l + u->len <= a) {
        return 0;
    } else if (a <= l && l + u->len <= b) {
        return u->sub;
    } else {
        u->push();
        return query(u->to[0], a, b, l) + query(u->to[1], a, b, l + u->len / 2);
    }
}

void merge(trie *&u, trie *v) {
    if (!u || !v) {
        u = u ? u : v;
    } else if (u->len == 1) {
        u = new trie(1, 1);
    } else {
        u->push(), v->push();
        for (int i = 0; i < 2; ++i) {
            merge(u->to[i], v->to[i]);
        }
        u->pull();
    }
}

void insert(trie *&u, trie *v, int a, int l) {
    if (u->len == v->len) {
        merge(u, v);
    } else {
        u->push();

        int d = 0;
        if (a >= l + u->len / 2) {
            l += u->len / 2;
            d = 1;
        }

        if (!u->to[d]) {
            u->to[d] = new trie(0, u->len / 2);
        }

        insert(u->to[d], v, a, l);

        u->pull();
    }
}

void erase(trie *&u, int a, int b, vector<pair<trie*, int>> &out, int l) {
    if (!u || b <= l || l + u->len <= a) {
        return;
    } else if (a <= l && l + u->len <= b) {
        out.push_back({u, l});
        u = nullptr;
    } else {
        u->push();
        erase(u->to[0], a, b, out, l);
        erase(u->to[1], a, b, out, l + u->len / 2);
        u->pull();
    }
}

void trim(trie *u, int x) {
    if (!u || (u->full & x) == 0) {
        return;
    }

    u->push();

    if ((u->full & x & (u->len / 2)) > 0) {
        merge(u->to[0], u->to[1]);
        u->to[1] = nullptr;
    }

    for (auto c : u->to) {
        if (c) {
            trim(c, x);
        }
    }

    u->pull();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    trie *root = new trie(0, N);

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        insert(root, new trie(1, 1), a, 0);
    }

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 4) {
            cout << query(root, l, r + 1, 0) << "\n";
        } else {
            vector<pair<trie*, int>> nodes;
            erase(root, l, r + 1, nodes, 0);

            if (!root) {
                root = new trie(0, N);
            }

            int x;
            cin >> x;

            for (auto [range, prefix] : nodes) {
                if (t == 1) {
                    prefix &= x;
                    trim(range, ~x);
                    range->apply(~x, 0, 0);
                } else if (t == 2) {
                    prefix |= x;
                    trim(range, x);
                    range->apply(0, x, 0);
                } else {
                    prefix ^= x;
                    range->apply(0, 0, x);
                }

                insert(root, range, prefix, 0);
            }
        }
    }
}