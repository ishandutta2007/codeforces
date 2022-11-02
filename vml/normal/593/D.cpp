#pragma comment(linker, "/STACK:1000000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <memory.h>
#include <ctime>
#include <set>
#include <map>
#include <math.h>
#include <queue>
#include <bitset>
#define ll long long
 
using namespace std;

const int maxn = (int)2e5 + 10, maxlog = 20;

vector <pair <int, ll> > ed[maxn];
pair <int, int> e[maxn];
int p[maxlog][maxn];
int pp[maxn];
ll d[maxn];
int h[maxn];

void dfs(int v, int par, ll dd, int hh) {
    p[0][v] = par;
    pp[v] = par;
    d[v] = dd;
    h[v] = hh;

    for (int i = 1; i < maxlog; i++) {
        p[i][v] = p[i - 1][p[i - 1][v]];
    }

    for (int i = 0; i < (int)ed[v].size(); i++) {
        if (ed[v][i].first != par) {
            dfs(ed[v][i].first, v, ed[v][i].second, hh + 1);
        }
    }
}

int lca(int v, int u) {
    if (h[v] < h[u]) {
        swap(v, u);
    }

    for (int i = maxlog - 1; i >= 0; i--) {
        if (h[p[i][v]] >= h[u]) {
            v = p[i][v];
        }
    }

    if (v == u) {
        return v;
    }

    for (int i = maxlog - 1; i >= 0; i--) {
        if (p[i][v] != p[i][u]) {
            v = p[i][v];
            u = p[i][u];
        }
    }

    return p[0][v];
}

vector <ll> now;

void go(int x, int v) {
    if (x == v) {
        return;
    }

    if (h[x] < h[v]) {
        return;
    }

    if ((int)now.size() >= 70) {
        return;
    }
    
    if (d[x] != 1) {
        now.push_back(d[x]);
        go(pp[x], v);
    } else {
        go(pp[x], v);
    }

    while (d[pp[x]] == 1 && pp[x] != 1) {
        pp[x] = pp[pp[x]];
    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        ll w;

        scanf("%d %d %I64d", &x, &y, &w);

        ed[x].push_back(make_pair(y, w));
        ed[y].push_back(make_pair(x, w));

        e[i] = make_pair(x, y);
    }

    dfs(1, 1, 1, 1);

    for (int i = 0; i < m; i++) {
        int tp;

        scanf("%d", &tp);

        if (tp == 1) {
            int x, y;
            ll z;

            scanf("%d %d %I64d", &x, &y, &z);

            int l = lca(x, y);

            now.clear();

            go(x, l);
            
            for (int i = 0; i < (int)now.size(); i++) {
                z /= now[i];
            }

            now.clear();
            
            if (z != 0) {
                go(y, l);
            }
            
            for (int i = (int)now.size() - 1; i >= 0; i--) {
                z /= now[i];
            }

            printf("%I64d\n", z);
        } else {
            int num;
            ll c;

            scanf("%d %I64d", &num, &c);
            num--;

            if (p[0][e[num].first] == e[num].second) {
                d[e[num].first] = c;
            } else {
                d[e[num].second] = c;
            }
        }
    }

    return 0;
}