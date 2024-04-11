//
//  main.cpp
//  
//
//  Created by Vlad Podtelkin on 17.01.14.
//  Copyright (c) 2014 Vlad Podtelkin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

#define N 1000500
#define INF 1000000000
#define M 99

using namespace std;

int x, y, z, n, px, py, pz, tx, ty, tz;
int f[M][M][M], ans, qb, qe;
vector<int> g[M][M][M];
char a[M][M];
struct Point {
    int x, y, z;
    Point() {}
    Point (int xx, int yy, int zz) : x(xx), y(yy), z(zz) {};
};
Point pred[M][M][M];
Point q[N];

void add(int x, int y, int z) {
    qe++;
    q[qe] = Point(x, y, z);
}

int main(int argc, const char * argv[])
{
    
    cin >> n;
    cin >> x >> y >> z;
    --x;
    --y;
    --z;
    tx = x;
    ty = y;
    tz = z;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                f[i][j][k] = INF;
    f[x][y][z] = 0;
    qb = -1;
    qe = 0;
    q[0] = Point(x, y, z);
    while (qb < qe) {
        qb++;
        int i = q[qb].x, j = q[qb].y, t = q[qb].z;
        for (int k = 0; k < n; k++) {
            if (i == j) continue;
            if (i == t) continue;
            if (i == k) continue;
            if (j == t) continue;
            if (j == k) continue;
            if (t == k) continue;
            if ((a[i][k] == a[j][t]) && (f[i][j][t] + 1 < f[k][j][t])) {
                f[k][j][t] = f[i][j][t] + 1;
                pred[k][j][t] = Point(i, j, t);
                add(k, j, t);
            }
            if ((a[j][k] == a[i][t]) && (f[i][j][t] + 1 < f[i][k][t])) {
                f[i][k][t] = f[i][j][t] + 1;
                pred[i][k][t] = Point(i, j, t);
                add(i, k, t);
            }
            if ((a[t][k] == a[i][j]) && (f[i][j][t] + 1 < f[i][j][k])) {
                f[i][j][k] = f[i][j][t] + 1;
                pred[i][j][k] = Point(i, j, t);
                add(i, j, k);
            }
        }
    }
    ans = INF;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++) {
                if (i == j) continue;
                if (i == k) continue;
                if (j == k) continue;
                if (f[i][j][k] < ans) {
                    x = i;
                    y = j;
                    z = k;
                    ans = f[i][j][k];
                }
            }
    if (ans == INF) {
        puts("-1");
        return 0;
    }
    printf("%d\n", ans);
    vector<pair<int, int> > an;
    
    while ((x != tx) || (y != ty) || (z != tz)) {
        int px = pred[x][y][z].x;
        int py = pred[x][y][z].y;
        int pz = pred[x][y][z].z;
        if (px != x)
//            printf("%d %d\n", 1 + px, 1 + x);
            an.push_back(make_pair(1 + px, 1 + x));
        if (py != y)
//            printf("%d %d\n", 1 + py, 1 + y);
            an.push_back(make_pair(1 + py, 1 + y));
        if (pz != z)
//            printf("%d %d\n", 1 + pz, 1 + z);
            an.push_back(make_pair(1 + pz, 1 + z));
        x = px;
        y = py;
        z = pz;
    }
    for (int i = an.size() - 1; i >= 0; i--)
        cout << an[i].first << " " << an[i].second << endl;
    return 0;
}