#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100100;
int n, m; char a[MAXN];

const bool ja[12] = {1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1};
const bool jb[12] = {0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1};
const bool jc[12] = {0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1};
const bool jab[12] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1};
const bool jbc[12] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1};

struct node {
    int f[12];
    node () { memset(f, 0x3f, sizeof f); }
    node operator + (const node &tmp) const {
        node ret = node();
        for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) {
            if (jab[i] && jc[j]) continue;
            if (ja[i] && jbc[j]) continue;
            bool nab = 0, nbc = 0; int to = -1;
            if (jab[i] || jab[j] || (ja[i] && jb[j])) nab = 1;
            if (jbc[i] || jbc[j] || (jb[i] && jc[j])) nbc = 1;
            if (nab || nbc) {
                if (nab && nbc) to = 11;
                else if (nab) {
                    if (jc[i] || jc[j]) to = 9;
                    else to = 3;
                }
                else {
                    if (ja[i] || ja[j]) to = 10;
                    else to = 5;
                }
            }
            else {
                bool na = ja[i] || ja[j], nb = jb[i] || jb[j], nc = jc[i] || jc[j];
                if (na && !nb && !nc) to = 0;
                if (!na && nb && !nc) to = 1;
                if (!na && !nb && nc) to = 2;
                if (na && nb && !nc) to = 4;
                if (!na && nb && nc) to = 6;
                if (na && !nb && nc) to = 7;
                if (na && nb && nc) to = 8;
            }
            assert(to != -1);
            ret.f[to] = min(ret.f[to], f[i] + tmp.f[j]);
        }
        return ret;
    }
    int val () { int ret = 0x3f3f3f3f; for (int i = 0; i < 12; i++) ret = min(ret, f[i]); return ret; }
} t[MAXN << 2];

void build (int l, int r, int x) {
    if (l == r) {
        t[x] = node(); t[x].f[0] = t[x].f[1] = t[x].f[2] = 1;
        t[x].f[a[l] - 'a'] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, x << 1); build(mid + 1, r, x << 1 | 1);
    t[x] = t[x << 1] + t[x << 1 | 1];
}
void modify (int pos, int k, int l, int r, int x) {
    if (l == r) {
        t[x] = node(); t[x].f[0] = t[x].f[1] = t[x].f[2] = 1;
        t[x].f[k] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(pos, k, l, mid, x << 1);
    else modify(pos, k, mid + 1, r, x << 1 | 1);
    t[x] = t[x << 1] + t[x << 1 | 1];
}


int main () {
    n = read(), m = read();
    int i, j; scanf("%s", a + 1);
    build(1, n, 1);
    // cout << t[1].val() << endl;
    while (m--) {
        int pos = read(); char c[2]; scanf("%s", c);
        modify(pos, c[0] - 'a', 1, n, 1);
        printf("%d\n", t[1].val());
    }
    return 0;
}