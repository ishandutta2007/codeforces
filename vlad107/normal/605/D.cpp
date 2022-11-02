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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e5 + 100;

struct Spell {
    int x, y, u, v, nom;
    Spell() {}
    bool operator < (const Spell &e) const {
        if (x != e.x) return x < e.x;
        return y < e.y;
    }
};

struct Tree {
    int l, r, lst;
    vector< pair<int, int> > vec;
    Tree() {}
};

Tree tr[4*N];
int n;
queue<int> q;
vector<int> pr, used;
vector<Spell> a;

void build(int x, int l, int r) {
    tr[x].l = a[l].x;
    tr[x].r = a[r].x;
    tr[x].lst = 0;
    if (l < r) {
        int mid = (l+r)/2;
        build(x + x + 1, l, mid);
        build(x + x + 2, mid + 1, r);
        tr[x].vec.resize(tr[x + x + 1].vec.size() + tr[x + x + 2].vec.size());
        merge(tr[x + x + 1].vec.begin(), tr[x + x + 1].vec.end(),
              tr[x + x + 2].vec.begin(), tr[x + x + 2].vec.end(),
              tr[x].vec.begin());
    } else {
        tr[x].vec.pb(mp(a[l].y, l));
    }
}

void go(int x, int u, int v, int idx) {
    if (u < tr[x].l) return;
    if (u >= tr[x].r) {
        while ((tr[x].lst < (int)tr[x].vec.size()) && (tr[x].vec[tr[x].lst].fr <= v)) {
            // cerr << tr[x].lst << endl;
            int nxt = tr[x].vec[tr[x].lst].sc;
            // cerr << nxt << endl;
            if (!used[nxt]) {
                used[nxt] = 1;
                pr[nxt] = idx;
                q.push(nxt);
            }
            ++tr[x].lst;
        }
        return;
    }
    if (u >= tr[x + x + 1].l) go(x + x + 1, u, v, idx);
    if (u >= tr[x + x + 2].l) go(x + x + 2, u, v, idx);
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].u, &a[i].v);
        a[i].nom = i;
    }
    sort(a.begin(), a.end());
    used.assign(n, 0);
    pr.assign(n, -1);
    build(0, 0, n-1);
    go(0, 0, 0, -1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        go(0, a[x].u, a[x].v, x);
    }
    int idx = 0;
    while (a[idx].nom != n-1) ++idx;
    if (!used[idx]) {
        puts("-1");
        return 0;
    }
    vector<int> ans;
    for (int i = idx; i != -1; i = pr[i]) ans.pb(a[i].nom);
    reverse(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) printf("%d ", ans[i]+1);
    puts("");
}