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
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define K 1010
#define N 10

using namespace std;

struct Point {
    int x, y, w;
    Point() {};
    Point(int x, int y, int w) : x(x), y(y), w(w) {};
};
int n, m, k, w;
char a[K][N][N];
int pred[K * K];
int used[K];
vector<int> g[K];
int nom[K], cnt = 0;
vector<Point> v;

bool cmp(Point u, Point v) {
    return u.w < v.w;
}

void dfs(int x, int px) {
    used[x] = true;
    cnt++;
    nom[x] = cnt;
    if (px == -1) {
        printf("%d 0\n", x + 1);
    } else {
        printf("%d %d\n", x + 1, px + 1);
    }
    for (int i = 0; i < g[x].size(); i++) {
        if (used[g[x][i]]) {
            continue;
        }
        dfs(g[x][i], x);
    }
}

int fs(int x) {
    if (pred[x] != x) {
        pred[x] = fs(pred[x]);
    }
    return pred[x];
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d\n", &n, &m, &k, &w);
    for (int it = 0; it < k; it++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%c", &a[it][i][j]);
            }
            scanf("\n");
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            int ct = 0;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (a[i][x][y] != a[j][x][y]) {
                        ct += w;
                    }
                }
            }
            v.push_back(Point(i, j, ct - n * m));
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < k; i++) {
        pred[i] = i;
    }
    int ans = k * n * m;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].w > 0) {
            break;
        }
        int x = fs(v[i].x);
        int y = fs(v[i].y);
        if (x == y) {
            continue;
        }
        ans += v[i].w;
        pred[x] = y;
        g[v[i].x].push_back(v[i].y);
        g[v[i].y].push_back(v[i].x);
    }
    printf("%d\n", ans);
    for (int i = 0; i < k; i++) {
        if (!used[i]) {
            dfs(i, -1);
        }
    }
}