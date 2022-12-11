#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int p[200005];

namespace fio {
    const int BSIZE = 524288;
    char buffer[BSIZE];
    int p = BSIZE;
    inline char readChar() {
        if(p == BSIZE) {
            fread(buffer, 1, BSIZE, stdin);
            p = 0;
        }
        return buffer[p++];
    }
    int readInt() {
        char c = readChar();
        while ((c < '0' || c > '9') && c != '-') {
            c = readChar();
        }
        int ret = 0;
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + c - '0';
            c = readChar();
        }
        return ret;
    }

    char outbuf[BSIZE + 30];
    int p2 = 0;
    void flush()
    {
        fwrite(outbuf, 1, p2, stdout);
        p2 = 0;
    }

    void writeInt(long long t)
    {
        int r = p2;
        do
        {
            outbuf[r++] = t % 10 + '0';
            t /= 10;
        } while (t);
        reverse(outbuf + p2, outbuf + r);
        p2 = r;
        outbuf[p2++] = '\n';

        if (p2 > BSIZE) flush();
    }
}

// persistent segment tree impl: sum tree
// initial tree index is 0
namespace pstree {
    typedef int val_t;
    const int DEPTH = 18;
    const int TSIZE = 1 << 18;
    const int MAX_QUERY = 262144;
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

inline int getsum(int l, int r, int d, int u)
{
    if (l > r || d > u) return 0;
    return pstree::query(d, u, r) - pstree::query(d, u, l - 1);
}

inline long long X1(int t)
{
    return t * 1ll * (t - 1) / 2;
}

int main()
{
    int n, q;
    n = fio::readInt();
    q = fio::readInt();
    pstree::init();
    for (int i = 1; i <= n; i++)
    {
        p[i] = fio::readInt();
        pstree::update(p[i], 1, i - 1);
    }

    long long base = n * 1ll * (n - 1) / 2;

    for (int i = 0; i < q; i++)
    {
        int l, d, r, u;
        l = fio::readInt();
        d = fio::readInt();
        r = fio::readInt();
        u = fio::readInt();

        int _1 = getsum(1,      l - 1,  1, d - 1);
        int _2 = getsum(l,      r,      1, d - 1);
        int _3 = getsum(r + 1,  n,      1, d - 1);
        int _4 = getsum(1,      l - 1,  d, u);
        int _6 = getsum(r + 1,  n,      d, u);
        int _7 = getsum(1,      l - 1,  u + 1, n);
        int _8 = getsum(l,      r,      u + 1, n);
        int _9 = getsum(r + 1,  n,      u + 1, n);

        fio::writeInt(base -
            X1(_1) - 
            X1(_2) - 
            X1(_3) - 
            X1(_4) - 
            X1(_6) - 
            X1(_7) - 
            X1(_8) - 
            X1(_9) - 
            _1 * 1ll * (_2 + _3 + _4 + _7) -
            _2 * 1ll * _3 -
            _3 * 1ll * (_6 + _9) -
            _4 * 1ll * _7 -
            _6 * 1ll * _9 -
            _7 * 1ll * (_8 + _9) -
            _8 * 1ll * _9
        );
    }
    fio::flush();
    fflush(stdout);
    _Exit(0);
}