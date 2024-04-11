#include <bits/stdc++.h>
using namespace std;

int dat[100005];

struct RMQ
{
    static constexpr int TSIZE = 131072;
    int tree[TSIZE * 2];

    void init(int n, int *d)
    {
        memcpy(tree + TSIZE, d, sizeof(int) * n);
        for (int i = TSIZE - 1; i >= 1; i--)
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }

    int query(int l, int r)
    {
        l += TSIZE; r += TSIZE; int ret = INT_MAX;
        while (l <= r)
        {
            if (l & 1) ret = min(ret, tree[l++]);
            if (!(r & 1)) ret = min(ret, tree[r--]);
            l >>= 1; r >>= 1;
        }
        return ret;
    }
} rmq;

struct lazyprop
{
    // example implementation of sum tree
    static constexpr int TSIZE = 1048576; // always 2^k form && n <= TSIZE
    int segtree[TSIZE * 2], prop[TSIZE * 2];

    void relax(int nod, int l, int r) {
        if (prop[nod] == 0) return;
        if (l < r) {
            int m = (l + r) >> 1;
            segtree[nod << 1] = prop[nod];
            prop[nod << 1] = prop[nod];
            segtree[nod << 1 | 1] = prop[nod];
            prop[nod << 1 | 1] = prop[nod];
        }
        prop[nod] = 0;
    }
    int query(int nod, int l, int r, int s, int e) {
        if (r < s || e < l) return INT_MAX;
        if (s <= l && r <= e) return segtree[nod];
        relax(nod, l, r);
        int m = (l + r) >> 1;
        return min(query(nod << 1, l, m, s, e), query(nod << 1 | 1, m + 1, r, s, e));
    }
    void update(int nod, int l, int r, int s, int e, int val) {
        if (r < s || e < l) return;
        if (s <= l && r <= e) {
            segtree[nod] = val;
            prop[nod] = val;
            return;
        }
        relax(nod, l, r);
        int m = (l + r) >> 1;
        update(nod << 1, l, m, s, e, val);
        update(nod << 1 | 1, m + 1, r, s, e, val);
        segtree[nod] = min(segtree[nod << 1], segtree[nod << 1 | 1]);
    }
} lazy;
// usage:
// seg_update(1, 0, n - 1, qs, qe, val);
// seg_query(1, 0, n - 1, qs, qe);

int n, k;

int get_raw(int l, int r)
{
    int lbkt = l / n;
    int rbkt = r / n;
    if (lbkt == rbkt)
    {
        return rmq.query(l % n, r % n);
    }
    else if (lbkt + 1 == rbkt)
    {
        return min(rmq.query(l % n, n - 1), rmq.query(0, r % n));
    }
    else
    {
        return rmq.query(0, n - 1);
    }
}

vector<int> coord;

struct query
{
    int type, l, r, x;
} qry[100005];

int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++) scanf("%d",&dat[i]);
    rmq.init(n, dat);

    int q;
    scanf("%d",&q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d%d",&qry[i].type, &qry[i].l, &qry[i].r);
        --qry[i].l;
        --qry[i].r;
        if (qry[i].type == 1) scanf("%d",&qry[i].x);

        coord.push_back(qry[i].l);
        if (qry[i].l) coord.push_back(qry[i].l - 1);
        coord.push_back(qry[i].l + 1);
        coord.push_back(qry[i].r);
        if (qry[i].r) coord.push_back(qry[i].r - 1);
        coord.push_back(qry[i].r + 1);
    }

    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());

    for (int i = 0; i < coord.size() - 1; i++)
    {
        lazy.update(1, 0, lazy.TSIZE - 1, i, i, get_raw(coord[i], coord[i + 1] - 1));
    }

    for (int i = 0; i < q; i++)
    {
        int L = lower_bound(coord.begin(), coord.end(), qry[i].l) - coord.begin();
        int R = lower_bound(coord.begin(), coord.end(), qry[i].r) - coord.begin();

        if (qry[i].type == 1)
        {
            lazy.update(1, 0, lazy.TSIZE - 1, L, R, qry[i].x);
        }
        else
        {
            printf("%d\n", lazy.query(1, 0, lazy.TSIZE - 1, L, R));
        }
    }
}