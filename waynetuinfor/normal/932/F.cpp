#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn];
vector<int> g[maxn];
long long ans[maxn];

struct convex {
    struct line_t {
        int a;
        long long b;
        line_t() {}
        line_t(int a, long long b): a(a), b(b) {}
        long long operator()(int x) const {
            return a * 1ll * x + b;
        }
    };
    struct node {
        node *lc, *rc;
        line_t lin;
        node(): lc(nullptr), rc(nullptr), lin(1e6, 1e16) {}
        void add(int l, int r, line_t tl) {
            bool lcp = lin(l) > tl(l);
            bool mcp = lin((l + r) >> 1) > tl((l + r) >> 1);
            if (mcp) swap(tl, lin);
            if (r - l == 1) return;
            if (lcp != mcp) {
                if (!lc) lc = new node();
                lc->add(l, (l + r) >> 1, tl);
            } else {
                if (!rc) rc = new node();
                rc->add((l + r) >> 1, r, tl);
            }
        }
        long long query(int l, int r, int x) {
            if (r - l == 1) return lin(x);
            if (x < (l + r) >> 1) {
                if (!lc) return lin(x);
                return min(lin(x), lc->query(l, (l + r) >> 1, x));
            } else {
                if (!rc) return lin(x);
                return min(lin(x), rc->query((l + r) >> 1, r, x));
            }
        }
    } *root;
    vector<line_t> lins;
    convex() {
        root = new node();
        lins.clear();
    }
    void insert(int a, long long b) {
        root->add(-maxn, maxn, line_t(a, b));
        lins.push_back(line_t(a, b));
    }
    void insert(line_t tl) {
        root->add(-maxn, maxn, tl);
        lins.push_back(tl);
    }
    long long eval(int x) const {
        return root->query(-maxn, maxn, x);
    }
    int size() const {
        return (int)lins.size();
    }
};

convex *ch[maxn];

void dfs(int x, int p) {
    ch[x] = new convex();
    bool lf = true;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        if (u == p) continue;
        dfs(u, x);
        lf = false;
        if (ch[u]->size() > ch[x]->size()) 
            swap(ch[u], ch[x]);
        for (int j = 0; j < ch[u]->size(); ++j)
            ch[x]->insert(ch[u]->lins[j]);
    } 
    if (lf) {
        ch[x]->insert(b[x], 0);
        ans[x] = 0;
    } else {
        ans[x] = ch[x]->eval(a[x]);
        ch[x]->insert(b[x], ans[x]);
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) printf("%lld ", ans[i]);
    puts("");
    return 0;
}