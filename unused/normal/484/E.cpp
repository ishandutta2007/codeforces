#include <cstdio>
#include <queue>
#include <tuple>
#include <set>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <random>
#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
using namespace std;

// persistent segment tree impl: sum tree
// initial tree index is 0
namespace pstree {
    struct val_t
    {
        int llen, rlen, size, maxval;
        val_t operator+(val_t rhs) const
        {
            val_t ret;
            ret.llen = llen == size ? size + rhs.llen : llen;
            ret.rlen = rhs.rlen == rhs.size ? rlen + rhs.size : rhs.rlen;
            ret.size = size + rhs.size;
            ret.maxval = max({ maxval, rhs.maxval, ret.llen, ret.rlen, rlen + rhs.llen });

            return ret;
        }
    };
    const int DEPTH = 17;
    const int TSIZE = 1 << 17;
    const int MAX_QUERY = 100001;

    struct node {
        val_t v;
        node* l, * r;
    } npoll[TSIZE * 2 + MAX_QUERY * (DEPTH + 1)], * head[MAX_QUERY + 1];

    int pptr, last_q;

    void init() {
        for (int i = TSIZE - 1; i < 2 * TSIZE - 1; i++) {
            npoll[i].v = { 1, 1, 1, 1 };
        }
        for (int i = TSIZE - 2; i >= 0; i--) {
            npoll[i].l = &npoll[i * 2 + 1];
            npoll[i].r = &npoll[i * 2 + 2];
            npoll[i].v = npoll[i * 2 + 1].v + npoll[i * 2 + 2].v;
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
        node* old = head[prev], * now = head[last_q];

        int flag = 1 << DEPTH;
        node* parents[DEPTH + 1];
        for (int depth = 0;; depth++) {
            parents[depth] = now;
            flag >>= 1;
            if (flag == 0) {
                now->l = now->r = nullptr;
                now->v = { val, val, 1, val };

                for (int p = depth - 1; p >= 0; p--)
                {
                    parents[p]->v = parents[p]->l->v + parents[p]->r->v;
                }
                break;
            }
            if (flag & pos) {
                now->l = old->l;
                now->r = &npoll[pptr++];
                now = now->r, old = old->r;
            }
            else {
                now->r = old->r;
                now->l = &npoll[pptr++];
                now = now->l, old = old->l;
            }
        }
        return last_q;
    }

    val_t query(int s, int e, int l, int r, node* n) {
        if (s == l && e == r) return n->v;
        int m = (l + r) / 2;
        if (m >= e) return query(s, e, l, m, n->l);
        else if (m < s) return query(s, e, m + 1, r, n->r);
        else return query(s, m, l, m, n->l) + query(m + 1, e, m + 1, r, n->r);
    }

    // query summation of [s, e] at time t
    val_t query(int s, int e, int t) {
        s = max(0, s); e = min(TSIZE - 1, e);
        return query(s, e, 0, TSIZE - 1, head[t]);
    }
}

int dat[100005];
int coord[100005];
int cr;
vector<int> events[100005];
int ttime[100005];

int main()
{
    pstree::init();

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dat[i]);
    }
    memcpy(coord, dat, sizeof(int) * n);
    sort(coord, coord + n);
    cr = unique(coord, coord + n) - coord;

    for (int i = 0; i < n; i++)
    {
        dat[i] = lower_bound(coord, coord + cr, dat[i]) - coord;
        events[dat[i] + 1].push_back(i);
    }

    int last = 0;
    for (int i = 1; i <= cr; i++)
    {
        for (int x : events[i])
        {
            last = pstree::update(x, 0, last);
        }

        ttime[i] = last;
    }

    int q;
    scanf("%d", &q);
    while (q--)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);

        int lo = 1, hi = cr - 1, ans = 0;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            auto res = pstree::query(a - 1, b - 1, ttime[mid]);
            if (res.maxval >= w)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        printf("%d\n", coord[ans]);
    }
}