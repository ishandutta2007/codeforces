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

const int V = 100100;
const int N = 400100;

struct Node {
    int l, r, mx, lazy;
}tr[4 * N];

void init(int id, int l, int r) {
    tr[id].l = l;
    tr[id].r = r;
    tr[id].mx = 0;
    tr[id].lazy = 0;
    if (l == r) return;
    int mid = (l + r) / 2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
}

void down(int id) {
    if (tr[id].lazy == 1) {
        tr[id * 2].lazy = tr[id * 2 + 1].lazy = 1;
        tr[id * 2].mx = tr[id * 2 + 1].mx = 1;
    }
}

void update(int id, int l, int r) {
    if (tr[id].l == l && tr[id].r == r) {
        tr[id].lazy = 1;
        tr[id].mx = 1;
        return;
    }
    int mid = (tr[id].l + tr[id].r) / 2;
    down(id);
    if (r <= mid) update(id * 2, l, r);
    else if (l > mid) update(id * 2 + 1, l, r);
    else {
        update(id * 2, l, mid);
        update(id * 2 + 1, mid + 1, r);
    }
    tr[id].mx = max(tr[id * 2].mx, tr[id * 2 + 1].mx);
}

int read(int id, int l, int r) {
    if (tr[id].l == l && tr[id].r == r) {
        return tr[id].mx;
    }
    int mid = (tr[id].l + tr[id].r) / 2;
    down(id);
    if (r <= mid) return read(id * 2, l, r);
    else if (l > mid) return read(id * 2 + 1, l, r);
    else {
        int a = read(id * 2, l, mid);
        int b = read(id * 2 + 1, mid + 1, r);
        return max(a, b);
    }
}

int v[N];

struct P {
    int t[4];
}p[V];

struct Event {
    //type 1: query, -1: add
    int t, type, id;
}e[2 * V];


Event event(int _t, int _type, int _id) {
    Event res;
    res.t = _t;
    res.type = _type;
    res.id = _id;
    return res;
}

bool cmpe(Event x, Event y) {
    if (x.t != y.t) return x.t < y.t;
    return x.type > y.type;
}

int n;
int main() {
    while (~scanf("%d", &n)) {
        int m = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                scanf("%d", &p[i].t[j]);
                v[m++] = p[i].t[j];
            }
        }
        map<int, int> mp;
        sort(v, v + m);
        int idx = 0;
        for (int i = 0; i < m; ++i) {
            if (i != 0 && v[i] == v[i - 1]) continue;
            mp[v[i]] = ++idx;
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 4; ++j)
                p[i].t[j] = mp[p[i].t[j]];

        bool ok = true;
        m = 0;
        for (int i = 0; i < n; ++i) {
            e[m++] = event(p[i].t[0], 1, i);
            e[m++] = event(p[i].t[1], -1, i);
        }
        sort(e, e + m, cmpe);
        init(1, 1, idx);
        //puts("OK");
        for (int i = 0; i < m; ++i) {
            int j = e[i].id;
            //printf("%d %d %d %d %d\n", e[i].t, e[i].type, j, p[j].t[2], p[j].t[3]);
            if (e[i].type == -1) {
                update(1, p[j].t[2], p[j].t[3]);
            } else {
                int mx = read(1, p[j].t[2], p[j].t[3]);
                if (mx == 1) ok = false;
            }
        }

        m = 0;
        for (int i = 0; i < n; ++i) {
            e[m++] = event(p[i].t[2], 1, i);
            e[m++] = event(p[i].t[3], -1, i);
        }
        sort(e, e + m, cmpe);
        init(1, 1, idx);
        for (int i = 0; i < m; ++i) {
            int j = e[i].id;
            if (e[i].type == -1) {
                update(1, p[j].t[0], p[j].t[1]);
            } else {
                int mx = read(1, p[j].t[0], p[j].t[1]);
                if (mx == 1) ok = false;
            }
        }
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
2
1 2 3 6
3 4 7 8

3
1 3 2 4
4 5 6 7
3 4 5 5

6
1 5 2 9
2 4 5 8
3 6 7 11
7 10 12 16
8 11 13 17
9 12 14 18

*/