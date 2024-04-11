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

#define pb push_back
#define mp make_pair
#define y0 y00000000
#define y1 y11111111
#define next nextttt
#define prev prevvvv

using namespace std;

const int COL = 0;
const int ROW = 1;
const int N = 4e5;

struct Tree {
    int l, r, val;
};

struct Quest {
    int x, y;
    char c;

    void read() {
        scanf("%d %d %c\n", &x, &y, &c);
    }
};

Quest quest[N];
int was[2 * N];
Tree tr[2][4 * N];

int get(int x, int id, int nom) {
    if (tr[id][x].l == tr[id][x].r) {
        return tr[id][x].val;
    }
    tr[id][x + x + 1].val = max(tr[id][x].val, tr[id][x + x + 1].val);
    tr[id][x + x + 2].val = max(tr[id][x].val, tr[id][x + x + 2].val);
    if (nom <= tr[id][x + x + 1].r) {
        return get(x + x + 1, id, nom);
    } else {
        return get(x + x + 2, id, nom);
    }
}

void setm(int x, int id, int l, int r, int val) {
    if ((tr[id][x].l == l) && (tr[id][x].r == r)) {
        tr[id][x].val = max(val, tr[id][x].val);
        return;
    }
    if (l <= tr[id][x + x + 1].r) {
        setm(x + x + 1, id, l, min(r, tr[id][x + x + 1].r), val);
    }
    if (r >= tr[id][x + x + 2].l) {
        setm(x + x + 2, id, max(l, tr[id][x + x + 2].l), r, val);
    }
}

void build(int id, int x, int l, int r) {
    tr[id][x].l = l;
    tr[id][x].r = r;
    tr[id][x].val = 0;
    int mid = (l + r) / 2;
    if (l != r) {
        build(id, x + x + 1, l, mid);
        build(id, x + x + 2, mid + 1, r);
    }
}

int main() {
    // freopen("c.in", "r", stdin);
    int n, m;
    scanf("%d%d\n", &n, &m);
    vector<int> vx, vy;
    vx.pb(0);
    vy.pb(0);
    for (int i = 0; i < m; i++) {
        quest[i].read();
        vx.pb(quest[i].x);
        vy.pb(quest[i].y);
    }
    sort(vx.begin(), vx.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    sort(vy.begin(), vy.end());
    vy.resize(unique(vy.begin(), vy.end()) - vy.begin());

    build(COL, 0, 0, vx.size() - 1);
    build(ROW, 0, 0, vy.size() - 1);

    for (int i = 0; i < m; i++) {
        char c = quest[i].c;
        int x = lower_bound(vx.begin(), vx.end(), quest[i].x) - vx.begin();
        int y = lower_bound(vy.begin(), vy.end(), quest[i].y) - vy.begin();
        if (was[x]) {
            puts("0");
            continue;
        }
        was[x] = 1;
        if (c == 'U') {
            int idy = get(0, COL, x);
            // cerr << vx[x] << " " << vy[idy] << endl;
            printf("%d\n", vy[y] - vy[idy]);
            setm(0, ROW, idy + 1, y, x);
        } else {
            int idx = get(0, ROW, y);
            printf("%d\n", vx[x] - vx[idx]);
            // cerr << vx[idx] << endl;
            // cerr << vx[x] << endl;
            // cerr << y << endl;
            setm(0, COL, idx + 1, x, y);
        }
    }
}