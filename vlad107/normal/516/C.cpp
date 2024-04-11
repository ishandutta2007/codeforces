#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

const int N = 5e5;

struct Node {
    long long ma, mb, ms, sh;
    int l, r;
    Node() {}
};

Node tr[N];
int n, m, h[N], d[N];

Node upd(const Node& u, const Node& v) {
    Node res;
    res.l = u.l;
    res.r = v.r;
    res.sh = v.sh + u.sh;
    res.ma = max(u.ma, v.ma - u.sh);
    res.mb = max(u.mb, v.mb + u.sh);
    res.ms = max(u.ms, v.ms);
    res.ms = max(res.ms, u.ma + v.mb + u.sh);
    return res;
}

void build(int x, int l, int r) {
    tr[x].l = l;
    tr[x].r = r;
    if (l == r) {
        tr[x].ma = 2 * h[l];
        tr[x].mb = 2 * h[l];
        tr[x].ms = 0;
        tr[x].sh = (l ? d[l - 1] : d[n - 1]);
        tr[x].ma -= tr[x].sh;
        tr[x].mb += tr[x].sh;
    } else {
        int mid = (l + r) / 2;
        build(x + x + 1, l, mid);
        build(x + x + 2, mid + 1, r);
        tr[x] = upd(tr[x + x + 1], tr[x + x + 2]);
    }
}

Node get(int x, int l, int r) {
    if ((tr[x].l == l) && (tr[x].r == r)) {
        return tr[x];
    }
    if (l >= tr[x + x + 2].l) return get(x + x + 2, l, r); else
    if (r <= tr[x + x + 1].r) return get(x + x + 1, l, r); else
    return upd(get(x + x + 1, l, min(r, tr[x + x + 1].r)),
               get(x + x + 2, max(l, tr[x + x + 2].l), r)); 
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    build(0, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        Node res;
        if (x > y) {
            res = get(0, y + 1, x - 1);
        } else {
            if (y == n - 1) res = get(0, 0, x - 1); else
            if (x == 0) res = get(0, y + 1, n - 1); else
            res = upd(get(0, y + 1, n - 1), get(0, 0, x - 1));  
        }
        printf("%I64d\n", res.ms);
    }
}