#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 3e5 + 10;
int n, qn, a[N];
namespace Seg {
    const int S = N << 2;
    int tg[S];
    pii mn[S];
    inline void PushUp(int v) {
        mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
    }
    inline void SetAdd(int v, int z) {
        tg[v] += z;
        mn[v].first += z;
    }
    inline void PushDown(int v) {
        if (tg[v]) {
            SetAdd(v << 1, tg[v]);
            SetAdd(v << 1 | 1, tg[v]);
            tg[v] = 0;
        }
    }
    inline void Build(int v = 1, int l = 1, int r = n) {
        if (l == r) { 
            mn[v] = pii(l - a[l], l);
            if (mn[v].first < 0) mn[v].first = 1e9;
            return;
        }
        int mid = (l + r) >> 1;
        Build(v << 1, l, mid); Build(v << 1 | 1, mid + 1, r);
        PushUp(v);
    }
    inline void Add(int x, int y, int z, int v = 1, int l = 1, int r = n) {
        // printf("Add  %d %d %d\n", x, y, z);
        if (x <= l && r <= y) { SetAdd(v, z); return; }
        PushDown(v);
        int mid = (l + r) >> 1;
        if (x <= mid) Add(x, y, z, v << 1, l, mid);
        if (y > mid) Add(x, y, z, v << 1 | 1, mid + 1, r);
        PushUp(v);
    }
    inline pii AskMin(int x, int y, int v = 1, int l = 1, int r = n) {
        if (x <= l && r <= y) return mn[v];
        if (x > r || y < l) return pii(2e9, 0);
        PushDown(v);
        int mid = (l + r) >> 1;
        return min(AskMin(x, y, v << 1, l, mid), AskMin(x, y, v << 1 | 1, mid + 1, r));
    }

}
namespace SaveAns {
    int f[N << 1 | 15];
    inline void Add(int x, int y) {
        for (int i = N + x; i; i >>= 1) f[i] += y;
    }
    inline int Ask(int x, int y) {
        int ans = 0;
        for (int l = N + x - 1, r = N + y + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
            if (~l & 1) ans += f[l ^ 1];
            if ( r & 1) ans += f[r ^ 1];
        }
        return ans;
    }
}
struct Query {
    int x, y, id;
} q[N];
inline bool Cmp(const Query &u, const Query &v) {
    return u.x < v.x;
}
int ans[N];
int main() {
    scanf("%d%d", &n, &qn);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= qn; ++i) {
        scanf("%d%d", &q[i].x, &q[i].y);
        q[i].id = i;
        ++q[i].x;
        q[i].y = n - q[i].y;
    }
    sort(q + 1, q + qn + 1, Cmp);
    Seg::Build();
    for (int ps = n, qid = qn; ps; --ps) {
        pii tmp;
        while ((tmp = Seg::AskMin(ps, n)).first <= 0) {
            int npos = tmp.second;
            SaveAns::Add(npos, 1);
            Seg::Add(npos, npos,1e9);
            if (npos < n) Seg::Add(npos + 1, n, -1);
        }
        while (qid > 0 && q[qid].x == ps) {
            ans[q[qid].id] = SaveAns::Ask(q[qid].x, q[qid].y);
            --qid;
        }
    }
    for (int i = 1; i <= qn; ++i) printf("%d\n", ans[i]);
    return 0;
}