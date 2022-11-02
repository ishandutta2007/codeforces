#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 2e5 + 10;
const int MM = 998244353;

struct Node_s {
    ll A, B;
    ll cnt;
    ll sum;
} tree[MAXN * 3];

int n, q;
int M;

void pushdown(int u) {
    if (u >= M) return ;
    int p = u * 2, q = p + 1;
    tree[u].sum = (tree[u].sum * tree[u].A + tree[u].B * tree[u].cnt) % MM;
    tree[p].B = (tree[u].A * tree[p].B + tree[u].B) % MM;
    tree[p].A = (tree[p].A * tree[u].A) % MM;
    tree[q].B = (tree[u].A * tree[q].B + tree[u].B) % MM;
    tree[q].A = (tree[q].A * tree[u].A) % MM;
    tree[u].A = 1;
    tree[u].B = 0;
}

void Update(int u, int L, int R, int l, int r, ll a, ll b) {
    // cout << "update " << u << ' ' << L << ' ' << R << ' ' << l << ' ' << r << ' ' << a << ' ' << b << endl;
    if (l == L && r == R) {
        tree[u].B = (tree[u].B * a + b) % MM;
        tree[u].A = (tree[u].A * a) % MM;
        return ;
    }
    pushdown(u);
    int M = (L + R) / 2;
    if (r <= M) Update(u * 2, L, M, l, r, a, b);
    else if (l > M) Update(u * 2 + 1, M + 1, R, l, r, a, b);
    else {
        Update(u * 2, L, M, l, M, a, b);
        Update(u * 2 + 1, M + 1, R, M + 1, r, a, b);
    }
    tree[u].sum = (tree[u * 2].A * tree[u * 2].sum + tree[u * 2 + 1].A * tree[u * 2 + 1].sum
            + tree[u * 2].B * tree[u * 2].cnt + tree[u * 2 + 1].B * tree[u * 2 + 1].cnt) % MM;
}

ll Query(int u, int L, int R, int l, int r) {
    if (l == L && r == R) {
        return (tree[u].sum * tree[u].A + tree[u].B * tree[u].cnt) % MM;
    }
    pushdown(u);
    int M = (L + R) / 2;
    if (r <= M) return Query(u * 2, L, M, l, r);
    else if (l > M) return Query(u * 2 + 1, M + 1, R, l, r);
    else {
        return (Query(u * 2, L, M, l, M) + Query(u * 2 + 1, M + 1, R, M + 1, r)) % MM;
    }
}

struct Node_t {
    int l, r;
    mutable int v;
    Node_t(const int &il, const int &ir, const int &iv) : l(il), r(ir), v(iv) {}
    inline bool operator<(const Node_t &o) const { return l < o.l; }
};

class Chtholly {
private:
    set<Node_t> odt;

public:
    void init(int n) {
        odt.insert(Node_t(1, n, 0));
    }

    auto split(int x) {
        if (x > n) return odt.end();
        auto it = --odt.upper_bound((Node_t){x, 0, 0});
        if (it->l == x) return it;
        int l = it->l, r = it->r, v = it->v;
        odt.erase(it);
        odt.insert(Node_t(l, x - 1, v));
        return odt.insert(Node_t(x, r, v)).first;
    }

    void assign(int l, int r, int v) {
        auto itr = split(r + 1), itl = split(l);
        odt.erase(itl, itr);
        odt.insert(Node_t(l, r, v));
    }

    void perform(int l, int r) {
        auto itr = split(r + 1), itl = split(l);
        for (; itl != itr; ++itl) {
            // std::cout << "preform " << itl->l << ' ' << itl->r << ' ' << itl->v << std::endl;
            if (itl->v) {
                Update(1, 1, M, itl->l, itl->r, 2, 0);
            }
            else {
                Update(1, 1, M, itl->l, itl->r, 1, 1);
            }
        }
    }
} shb[MAXN];

void solve(int casi) {
    scanf("%d%d", &n, &q);
    for (M = 1; M < n; M *= 2);
    for (int i = 1; i <= n; i++) {
        shb[i].init(n);
    }
    for (int i = 1; i <= 2 * M; i++) {
        tree[i].A = 1;
        tree[i].B = 0;
        tree[i].sum = 0;
        tree[i].cnt = 0;
    }
    for (int i = 1; i <= n; i++) {
        tree[i + M - 1].cnt = 1;
    }
    for (int i = M - 1; i >= 1; i--) {
        tree[i].cnt = tree[i * 2].cnt + tree[i * 2 + 1].cnt;
    }
    while (q--) {
        int op, l, r, x;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1) {
            scanf("%d", &x);
            shb[x].perform(l, r);
            shb[x].assign(l, r, 1);
        }
        else {
            printf("%lld\n", Query(1, 1, M, l, r));
        }
    }
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}