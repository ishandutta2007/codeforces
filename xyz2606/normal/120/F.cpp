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

const int N = 1e3;

int tot, g[N], nex[N], pre[N];
int Max, pos;

void add(int x, int y) {
    nex[++tot] = y; pre[tot] = g[x]; g[x] = tot;
}

void dfs(int x, int fa, int dis) {
    if (dis > Max) {
        Max = dis; pos = x;
    }
    for (int now = g[x]; now; now = pre[now]) {
        int y = nex[now];
        if (y == fa) continue;
        dfs(y, x, dis + 1);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        tot = 0;
        memset(g, 0, sizeof(g));
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m - 1; j++) {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y);
            add(y, x);
        }
        Max = 0, pos = 1;
        dfs(pos, 0, 0);
        Max = 0;
        dfs(pos, 0, 0);
        ans += Max;
    }
    printf("%d\n", ans);
    return 0;
}