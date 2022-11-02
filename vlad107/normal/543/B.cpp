#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector< vector<int> > g;
vector< vector<int> > d;

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    g.resize(n);
    d.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int s1, t1, l1, s2, t2, l2;
    scanf("%d%d%d", &s1, &t1, &l1); --s1; --t1;
    scanf("%d%d%d", &s2, &t2, &l2); --s2; --t2;
    for (int i = 0; i < n; i++) {
        d[i].assign(n, -1);
        d[i][i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int j = 0; j < g[x].size(); j++) {
                int y = g[x][j];
                if (d[i][y] < 0) {
                    d[i][y] = d[i][x] + 1;
                    q.push(y);
                }
            }
        }
    }
    if ((d[s1][t1] > l1) || (d[s2][t2] > l2)) {
        puts("-1");
        return 0;
    }
    int ans = d[s1][t1] + d[s2][t2];
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int k1 = d[s1][x] + d[x][y] + d[y][t1];
            int k2 = d[s2][x] + d[x][y] + d[y][t2];
            k2 = min(k2, d[s2][y] + d[y][x] + d[x][t2]);
            if ((k1 <= l1) && (k2 <= l2)) ans = min(ans, k1 + k2 - d[x][y]);
        }
    }
    cout << m - ans << endl;
}