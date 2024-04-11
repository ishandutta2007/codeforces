#include <bits/stdc++.h>
using namespace std;

// persistent segment tree impl: sum tree
// initial tree index is 0
namespace pstree {
    typedef int val_t;
    const int DEPTH = 16;
    const int TSIZE = 1 << 16;
    const int MAX_QUERY = 40000;
    struct node {
        val_t v;
        node *l, *r;
    } npoll[TSIZE * 2 + MAX_QUERY * (DEPTH + 1)], *head[MAX_QUERY + 1];
    int pptr, last_q;
    void init() {
        // zero-initialize, can be changed freely
        memset(&npoll[TSIZE - 1], 0, sizeof(node) * TSIZE);
        for (int i = TSIZE - 2; i >= 0; i--) {
            npoll[i].v = 0;
            npoll[i].l = &npoll[i*2+1];
            npoll[i].r = &npoll[i*2+2];
        }
        head[0] = &npoll[0];
        last_q = 0;
        pptr = 2 * TSIZE - 1;
    }
    // update val to pos
    // 0 <= pos < TSIZE
    // returns updated tree index
    int update(int pos, int val, int prev) {
        head[++last_q] = &npoll[pptr++];
        node *old = head[prev], *now = head[last_q];
        int flag = 1 << DEPTH;
        for (;;) {
            now->v = old->v + val;
            flag >>= 1;
            if (flag==0) {
                now->l = now->r = nullptr; break;
            }
            if (flag & pos) {
                now->l = old->l;
                now->r = &npoll[pptr++];
                now = now->r, old = old->r;
            } else {
                now->r = old->r;
                now->l = &npoll[pptr++];
                now = now->l, old = old->l;
            }
        }
        return last_q;
    }
    val_t query(int s, int e, int l, int r, node *n) {
        if (s == l && e == r) return n->v;
        int m = (l + r) / 2;
        if (m >= e) return query(s, e, l, m, n->l);
        else if (m < s) return query(s, e, m + 1, r, n->r);
        else return query(s, m, l, m, n->l) + query(m + 1, e, m + 1, r, n->r);
    }
    // query summation of [s, e] at time t
    val_t query(int s, int e, int t) {
        s = max(0, s); e = min(TSIZE - 1, e);
        if (s > e) return 0;
        return query(s, e, 0, TSIZE - 1, head[t]);
    }
}

int a[40000];
int last[40000];
int val[40000];
int dp1[35005], dp2[35005];
int n;
int *d, *e;

namespace fio {
    const int BSIZE = 524288;
    unsigned char buffer[BSIZE];
    int p = BSIZE;
    inline unsigned char readChar() {
        if(p == BSIZE) {
            fread(buffer, 1, BSIZE, stdin);
            p = 0;
        }
        return buffer[p++];
    }
    int readInt() {
        unsigned char c = readChar();
        while (c < '0') {
            c = readChar();
        }
        int ret = 0;
        while (c >= '0') {
            ret = ret * 10 + c - '0';
            c = readChar();
        }
        return ret;
    }
}

void init_segtree()
{
    pstree::init();

    for (int i = n; i >= 1; i--)
    {
        if (last[a[i]] == 0) last[a[i]] = 60000;
        val[i] = last[a[i]];
        last[a[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        pstree::update(val[i], 1, i - 1);
    }
}

int cost(int l, int r)
{
    return pstree::query(r + 1, 60000, r) - pstree::query(r + 1, 60000, l - 1);
}

void divide_and_conquer(int idx, int lo, int hi, int alo, int ahi)
{
    int mid = (lo + hi) / 2;
    e[mid] = INT_MIN;

    int cost = ::cost(min(mid, ahi) + 1, mid);
    int x;

    for (int i = min(mid, ahi); i >= alo; i--)
    {
        if (val[i] > mid) ++cost;

        int res = d[i - 1] + cost;
        if (e[mid] < res)
        {
            e[mid] = res;
            x = i;
        }
    }

    if (lo < mid) divide_and_conquer(idx, lo, mid - 1, alo, x);
    if (mid < hi) divide_and_conquer(idx, mid + 1, hi, x, ahi);
}

int main()
{
    int k;
    n = fio::readInt();
    k = fio::readInt();
    for (int i = 1; i <= n; i++) a[i] = fio::readInt();

    init_segtree();

    d = dp1; e = dp2;

    for (int i = 1; i <= k; i++, swap(d, e))
    {
        divide_and_conquer(i, 1, n, 1, n);
    }

    printf("%d\n", d[n]);
    fflush(stdout);
    _Exit(0);
}