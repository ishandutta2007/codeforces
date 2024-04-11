//
//  main.cpp
//  TaskC
//
//  Created by Vlad Podtelkin on 20.01.14.
//  Copyright (c) 2014 Podtelkin Vladislav. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define N 500500

using namespace std;

int tm, tin[N], tout[N], a[N], deg[N], n, m, sa[2][N];
vector<int> g[N];

void dfs(int x, int px, int t) {
    tm++;
    tin[x] = tm;
    deg[x] = t;
    for (int i = 0; i < g[x].size(); i++)
        if (g[x][i] != px)
            dfs(g[x][i], x, t + 1);
    tm++;
    tout[x] = tm;
}

void add0(int x, int tt, int val) {
    for (int t = tt; t < N; t = ((t | (t - 1)) + 1))
        sa[x][t] += val;
}

void add(int x, int ss, int ff, int val) {
    add0(x, ss, val);
    add0(x, ff + 1, -val);
}

int fsum(int x, int tt) {
    int sum = 0;
    for (int t = tt; t > 0; t = (t & (t - 1)))
        sum += sa[x][t];
    return sum;
}

int main(int argc, const char * argv[])
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0, 0);
    //cout << tin[1] << tout[1] << endl;
    for (int i = 0; i < m; i++) {
        int q, x, val;
        scanf("%d", &q);
        if (q == 1) {
            scanf("%d%d", &x, &val);
            add(deg[x] % 2, tin[x], tout[x], +val);
            add(1 - (deg[x] % 2), tin[x], tout[x], -val);
        } else {
            scanf("%d", &x);
            printf("%d\n", a[x] + fsum(deg[x] % 2, tin[x]));
        }
    }
    return 0;
}