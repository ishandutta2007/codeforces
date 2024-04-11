/*
Author: elfness@UESTC
*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;

const int V = 200100;

struct Node {
    int l, r;
    LL s;
    int cnt;
}tr[4 * V];

void init(int id, int l, int r) {
    tr[id].l = l;
    tr[id].r = r;
    tr[id].cnt = 0;
    tr[id].s = 0;
    if (l == r) return;
    int mid = (l + r) / 2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
}

void update(int id, int pos) {
    if (tr[id].l == pos && tr[id].r == pos) {
        tr[id].cnt = 1;
        tr[id].s = pos;
        return;
    }
    int mid = (tr[id].l + tr[id].r) / 2;
    if (pos <= mid) update(id * 2, pos);
    else update(id * 2 + 1, pos);
    tr[id].cnt = tr[id * 2].cnt + tr[id * 2 + 1].cnt;
    tr[id].s = tr[id * 2].s + tr[id * 2 + 1].s;
}

int f(int id, int K) {
    if (tr[id].l == tr[id].r) return tr[id].r;
    if (tr[id * 2].cnt >= K) return f(id * 2, K);
    else return f(id * 2 + 1, K - tr[id * 2].cnt);
}

int readcnt(int id, int l, int r) {
    if (tr[id].l == l && tr[id].r == r) return tr[id].cnt;
    int mid = (tr[id].l + tr[id].r) / 2;
    if (r <= mid) return readcnt(id * 2, l, r);
    else if (l > mid) return readcnt(id * 2 + 1, l, r);
    else {
        int a = readcnt(id * 2, l, mid);
        int b = readcnt(id * 2 + 1, mid + 1, r);
        return a + b;
    }
}

LL reads(int id, int l, int r) {
    if (tr[id].l == l && tr[id].r == r) return tr[id].s;
    int mid = (tr[id].l + tr[id].r) / 2;
    if (r <= mid) return reads(id * 2, l, r);
    else if (l > mid) return reads(id * 2 + 1, l, r);
    else {
        LL a = reads(id * 2, l, mid);
        LL b = reads(id * 2 + 1, mid + 1, r);
        return a + b;
    }
}

int a[V], b[V];

LL ans[V];
int n;

int main() {
    while (~scanf("%d", &n)) {
        //for (int i = 1; i <= n; ++i) a[i] = i;
        //random_shuffle(a + 1, a + 1 + n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) b[a[i]] = i;
        init(1, 1, n);
        LL rev = 0;
        for (int i = 1; i <= n; ++i) {
            rev += readcnt(1, b[i], n);
            update(1, b[i]);
            int mid = i / 2 + 1;
            int pm = f(1, mid);
            int cl = mid - 1;
            int cr = i - mid;
            LL sl = 0;
            if (pm != 1) sl = reads(1, 1, pm - 1);
            LL sr = 0;
            if (pm != n) sr = reads(1, pm + 1, n);
            //printf("%I64d %d %d %d %d %I64d %I64d\n", rev, b[i], pm, cl, cr, sl, sr);
            ans[i] = rev;
            ans[i] += (LL) pm * cl - sl - (LL) cl * (cl + 1) / 2;
            ans[i] += sr - (LL) pm * cr - (LL) cr * (cr + 1) / 2;
        }
        for (int i = 1; i <= n; ++i) printf("%I64d ", ans[i]);puts("");
        //puts("OK");
    }
    return 0;
}

/*
5
5 4 3 2 1
3
1 2 3
3
2 3 1
*/