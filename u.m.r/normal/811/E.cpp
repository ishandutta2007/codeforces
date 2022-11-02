#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e5 + 10;
const int MM = 1e9 + 7;

int n, m, q;

int M;

int a[MAXN][10];

struct SegNode {
    int l, r;
    int fa[20];
    int ans, cnt;
    void init(int idx = -1) {
        if (idx == -1) {
            l = r = -1;
        }
        else {
            fa[0] = fa[n] = 1;
            for (int i = 1; i < n; i++) {
                if (a[idx][i] == a[idx][i - 1]) {
                    fa[i] = fa[n + i] = fa[i - 1];
                }
                else {
                    fa[i] = fa[n + i] = fa[i - 1] + 1;
                }
            }
            ans = cnt = fa[n - 1];
            l = r = idx;
        }
    }
} tree[MAXN * 3];

int tag[100], umi[100], fa[100];
int ktr = 0;
int getfather(int x) {
    if (x == fa[x]) return x;
    else return fa[x] = getfather(fa[x]);
}

SegNode merge(const SegNode &p, const SegNode &q) {
    if (q.l == -1) return p;
    if (p.r + 1 != q.l) {
        cerr << "???" << endl;
        return p;
    }
    ktr++;
    for (int i = 1; i <= p.cnt + q.cnt; i++) {
        fa[i] = i;
    }
    SegNode res;
    res.l = p.l;
    res.r = q.r;
    res.ans = p.ans + q.ans;
    for (int i = 0; i < n; i++) {
        if (a[p.r][i] == a[q.l][i]) {
            int u = getfather(p.fa[n + i]);
            int v = getfather(q.fa[i] + p.cnt);
            if (u != v) {
                fa[u] = v;
                res.ans--;
            }
        }
    }
    res.cnt = 0;
    for (int i = 0; i < n; i++) {
        int u = getfather(p.fa[i]);
        if (tag[u] != ktr) {
            tag[u] = ktr;
            res.cnt++;
            umi[u] = res.cnt;
        }
        res.fa[i] = umi[u];
    }
    for (int i = 0; i < n; i++) {
        int u = getfather(q.fa[n + i] + p.cnt);
        if (tag[u] != ktr) {
            tag[u] = ktr;
            res.cnt++;
            umi[u] = res.cnt;
        }
        res.fa[n + i] = umi[u];
    }
    return res;
}

SegNode Query(int u, int L, int R, int l, int r) {
    if (L == l && R == r) {
        return tree[u];
    }
    int M = (L + R) / 2;
    if (r <= M) return Query(u * 2, L, M, l, r);
    else if (l > M) return Query(u * 2 + 1, M + 1, R, l, r);
    else {
        return merge(Query(u * 2, L, M, l, M),
            Query(u * 2 + 1, M + 1, R, M + 1, r));
    }
}

void solve(int casi){
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[j][i]);
        }
    }
    for (M = 1; M < m; M *= 2);
    for (int i = 1; i <= m; i++) {
        tree[M - 1 + i].init(i);
    }
    for (int i = m + 1; i <= M; i++) {
        tree[M - 1 + i].init();
    }
    for (int i = M - 1; i >= 1; i--) {
        tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        auto res = Query(1, 1, M, l, r);
        printf("%d\n", res.ans);
    }
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}