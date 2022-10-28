#include <bits/stdc++.h>
using namespace std;

struct splay_node {
    splay_node *child[2], *parent;
    bool reverse_tag;
    int value;
    splay_node(int value) : value(value) {
        child[0] = child[1] = parent = nullptr;
        reverse_tag = false;
    }
};

void reverse(splay_node *u) {
    swap(u->child[0], u->child[1]);
    u->reverse_tag ^= true;
}

int dir(splay_node *u) {
    if (!u->parent) return -1;
    if (u == u->parent->child[0]) return 0;
    if (u == u->parent->child[1]) return 1;
    return -1;
}

void connect(splay_node *p, splay_node *c, int dir) {
    if (p && dir != -1) p->child[dir] = c;
    if (c) c->parent = p;
}

void rotate(splay_node *u) {
    splay_node *p = u->parent, *g = p->parent, *c = u->child[dir(u) ^ 1];
    int prev_dir = dir(u);
    connect(g, u, dir(p));
    connect(p, c, prev_dir);
    connect(u, p, prev_dir ^ 1);
}

void push(splay_node *a) {
    if (a->reverse_tag) {
        for (auto c : a->child)
            if (c) reverse(c);
        a->reverse_tag = false;
    }
}

void pull(splay_node *a) {
    if (dir(a) != -1) pull(a->parent);
    push(a);
}

void splay(splay_node *u) {
    pull(u);
    while (dir(u) != -1) {
        splay_node *p = u->parent;
        if (dir(u) == dir(p)) rotate(p);
        rotate(u);
    }
}

void access(splay_node *u) {
    splay_node *p = u, *c = nullptr;
    while (p) {
        splay(p);
        p->child[1] = c;
        c = p, p = p->parent;
    }
    splay(u);
}

splay_node * get_root(splay_node *a) {
    access(a);
    while (a->child[0]) {
        a = a->child[0];
        push(a);
    }
    splay(a);
    return a;
}

void reroot(splay_node *a) {
    access(a);
    reverse(a);
}

void link(splay_node *a, splay_node *b) {
    reroot(b);
    b->parent = a;
}

void cut(splay_node *a, splay_node *b) {
    reroot(a);
    access(b);
    a->parent = b->child[0] = nullptr;
}

struct segtree {
    segtree *left, *right;
    pair<int, int> min_value;
    int lazy_add;

    segtree(int l, int r) {
        if (r - l > 1) {
            int m = (l + r) / 2;
            left = new segtree(l, m);
            right = new segtree(m, r); 
            pull();
        } else {
            min_value = {l, 1};
        }
        lazy_add = 0;
    }

    pair<int, int> query(int a, int b, int l, int r) {
        if (a <= l && r <= b) return min_value;
        if (b <= l || r <= a) return {INT_MAX, 0};

        push();
        int m = (l + r) / 2;

        auto [lmin, lcount] = left->query(a, b, l, m);
        auto [rmin, rcount] = right->query(a, b, m, r);
        
        return {min(lmin, rmin), (lmin <= rmin ? lcount : 0) + (rmin <= lmin ? rcount : 0)};
    }

    void update(int a, int b, int x, int l, int r) {
        if (a <= l && r <= b) apply(x);
        else if (b <= l || r <= a) return;
        else {
            push();
            int m = (l + r) / 2;
            left->update(a, b, x, l, m);
            right->update(a, b, x, m, r);
            pull();
        }
    }

    void apply(int x) {
        min_value.first += x, lazy_add += x;
    }

    void push() {
        if (lazy_add) {
            left->apply(lazy_add), right->apply(lazy_add);
            lazy_add = 0;
        }
    }

    void pull() {
        min_value.first = min(left->min_value.first, right->min_value.first);
        min_value.second = 0;
        for (auto i : {left, right}) {
            if (i->min_value.first == min_value.first)
                min_value.second += i->min_value.second;
        }
    }
};

const int D[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector grid(n, vector<int>(m));
    vector<pair<int, int>> pos(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j], --grid[i][j];
            pos[grid[i][j]] = {i, j};
        }
    }

    vector nodes(n, vector<splay_node*>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            nodes[i][j] = new splay_node(i * m + j);
        }
    }

    long long answer = 0;
    segtree *range_min = new segtree(0, n * m);
    for (int l = 0, r = 0; l < n * m; ++l) {
        while (r < n * m) {
            auto [x, y] = pos[r];

            vector<array<int, 3>> neighbors;

            for (int d = 0; d < 4; ++d) {
                int x_oth = x + D[d], y_oth = y + D[(d + 1) % 4];
                if (0 <= x_oth && x_oth < n && 0 <= y_oth && y_oth < m) {
                    if (l <= grid[x_oth][y_oth] && grid[x_oth][y_oth] < r) {
                        neighbors.push_back({get_root(nodes[x_oth][y_oth])->value, x_oth, y_oth});
                    }
                }
            }

            sort(neighbors.begin(), neighbors.end());

            bool tree = true;
            for (int i = 1; i < (int) neighbors.size(); ++i) tree &= (neighbors[i][0] != neighbors[i - 1][0]);

            if (!tree) break;

            for (auto [_, x_oth, y_oth] : neighbors) {
                range_min->update(grid[x][y], n * m, -1, 0, n * m);
                link(nodes[x_oth][y_oth], nodes[x][y]);
            }
            ++r;
        }

        answer += range_min->query(l, r, 0, n * m).second;
        range_min->update(l, n * m, -1, 0, n * m);

        auto [x, y] = pos[l];
        for (int d = 0; d < 4; ++d) {
            int x_oth = x + D[d], y_oth = y + D[(d + 1) % 4];
            if (0 <= x_oth && x_oth < n && 0 <= y_oth && y_oth < m) {
                if (l < grid[x_oth][y_oth] && grid[x_oth][y_oth] < r) {
                    range_min->update(grid[x_oth][y_oth], n * m, 1, 0, n * m);
                    cut(nodes[x_oth][y_oth], nodes[x][y]);
                }
            }
        }
    }

    cout << answer << "\n";
}