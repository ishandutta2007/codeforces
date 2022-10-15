#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>

using namespace std;

const int L = 1e3, N = 1e2;

int n, l;
char st[L];
int f[L][N], g[L][N];

int dfs(int x, int y) {
    if (f[x][y] == -1) {
        if (x == l) f[x][y] = l;
        else if (g[x][y] == 1) f[x][y] = x;
        else {
            if (st[x] == '0') {
                f[x][y] = dfs(x + 1, y);
                if (y < n) {
                    if (g[x][y + 1] == 1) f[x][y] = max(f[x][y], x);
                    else f[x][y] = max(f[x][y], dfs(x + 1, y + 1));
                }
                if (y > 1) {
                    if (g[x][y - 1] == 1) f[x][y] = max(f[x][y], x);
                    else f[x][y] = max(f[x][y], dfs(x + 1, y - 1));
                }
            }
            else {
                for (int i = 1; i <= n; i++) f[x][y] = max(f[x][y], dfs(x + 1, i));
            }
        }
    }
    return f[x][y];
}

int main() {
    int m, k;
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", st); scanf("%s", st);
    int dir = 1;
    if (st[0] == 'h') dir = -1;
    scanf("%s", st);
    l = strlen(st);
    memset(f, -1, sizeof(f));
    memset(g, -1, sizeof(g));
    g[0][k] = 1;
    for (int i = 1; i <= l; i++) {
        if (k + dir > n || k + dir < 1) dir *= -1;
        k += dir;
        g[i][k] = 1;
    }
    int ans = dfs(0, m);
    if (ans == l) printf("Stowaway\n");
    else printf("Controller %d\n", ans);
    return 0;
}