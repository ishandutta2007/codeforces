#include <bits/stdc++.h>
using namespace std;

constexpr int TSIZE = 524288;
constexpr int INF = (int)1e9 + 1;

using oper = const int &(*)(const int &, const int &);

struct segtree
{
    const int init;
    vector<int> tree;
    oper op;

    segtree(int init, oper op) : init(init), tree(TSIZE * 2, init), op(op) {}

    int query(int l, int r)
    {
        int res = init;
        l += TSIZE; r += TSIZE;

        while (l <= r)
        {
            if (l & 1) res = op(res, tree[l++]);
            if (!(r & 1)) res = op(res, tree[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }

    void update(int l, int r, int val)
    {
        l += TSIZE; r += TSIZE;

        while (l <= r)
        {
            if (l & 1) tree[l] = op(val, tree[l]), ++l;
            if (!(r & 1)) tree[r] = op(val, tree[r]), --r;
            l >>= 1; r >>= 1;
        }
    }

    int query(int pos)
    {
        int res = init;
        for (pos += TSIZE; pos; pos >>= 1) res = op(res, tree[pos]);
        return res;
    }

    void update(int pos, int val)
    {
        tree[pos += TSIZE] = val;
        for (pos >>= 1; pos; pos >>= 1) tree[pos] = op(tree[pos << 1], tree[pos << 1 | 1]);
    }
};

segtree stree1(INF, min<int>);
segtree stree2(0, max<int>);

int t[300005], l[300005], r[300005], x[300005];
int mv[300005], ans[300005];
set<int> used;

int main()
{
    memset(mv, -1, sizeof(mv));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &t[i]);
        if (t[i] == 1)
        {
            scanf("%d%d%d", &l[i], &r[i], &x[i]);
            stree1.update(l[i], r[i], x[i]);
        }
        else
        {
            scanf("%d%d", &l[i], &r[i]);
            if (mv[l[i]] == -1) mv[l[i]] = stree1.query(l[i]);
            stree1.tree[l[i] + TSIZE] = r[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (mv[i] == -1) mv[i] = stree1.query(i);
        stree2.update(i, mv[i]);
    }

    for (int i = 0; i < m; i++)
    {
        if (t[i] == 1)
        {
            if (stree2.query(l[i], r[i]) != x[i])
            {
                printf("NO\n");
                return 0;
            }
        }
        else
        {
            stree2.update(l[i], r[i]);
        }
    }

    printf("YES\n");

    used.insert(INF);
    set<pair<int, int>> st;
    int now = 0;

    for (int i = 1; i <= n; i++)
    {
        if (used.insert(mv[i]).second || mv[i] == 0)
        {
            ans[i] = mv[i];
            now |= mv[i];
        }
        else
        {
            st.emplace(-mv[i], i);
        }
    }

    for (auto &e : st)
    {
        int i = e.second;
        if (mv[i] == INF) mv[i]--;
        int res = 0;
        bool full = true;
        for (int flag = 1<<30; flag; flag >>= 1)
        {
            if (!full) res |= flag;
            else if (mv[i] & flag)
            {
                if (!(now & flag)) res |= flag;
                else full = false;
            }
        }

        ans[i] = res;
        now |= res;
    }

    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);

    printf("\n");
}