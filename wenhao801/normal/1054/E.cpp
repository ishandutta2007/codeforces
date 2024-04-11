#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 303;
int n, m; struct inv { int x1, y1, x2, y2; inv (int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0) { x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2; } };
vector <inv> v, ans;
queue <bool> a[MAXN][MAXN];

void solve () {
    int i, j;
    while (!a[1][1].empty()) {
        if (!a[1][1].front()) a[1][2].push(0), v.push_back(inv(1, 1, 1, 2));
        else v.push_back(inv(1, 1, n, 1));
        a[1][1].pop();
    }
    while (!a[n][1].empty()) {
        if (a[n][1].front()) a[n][2].push(1), v.push_back(inv(n, 1, n, 2));
        else v.push_back(inv(n, 1, 1, 1));
        a[n][1].pop();
    }
    for (i = 2; i <= n - 1; i++) while (!a[i][1].empty()) {
        if (!a[i][1].front()) v.push_back(inv(i, 1, 1, 1));
        else v.push_back(inv(i, 1, n, 1));
        a[i][1].pop();
    }
    for (i = 2; i <= n - 1; i++) for (j = 2; j <= m; j++) while (!a[i][j].empty()) {
        if (!a[i][j].front()) a[1][j].push(0), v.push_back(inv(i, j, 1, j));
        else a[n][j].push(1), v.push_back(inv(i, j, n, j));
        a[i][j].pop();
    }
    for (i = 2; i <= m; i++) {
        while (!a[1][i].empty()) {
            if (!a[1][i].front()) v.push_back(inv(1, i, 1, 1));
            else v.push_back(inv(1, i, n, i)), a[n][i].push(1);
            a[1][i].pop();
        }
        while (!a[n][i].empty()) {
            if (a[n][i].front()) v.push_back(inv(n, i, n, 1));
            else v.push_back(inv(n, i, 1, i)), a[1][i].push(0);
            a[n][i].pop();
        }
        while (!a[1][i].empty()) {
            if (!a[1][i].front()) v.push_back(inv(1, i, 1, 1));
            else v.push_back(inv(1, i, n, i)), a[n][i].push(1);
            a[1][i].pop();
        }
        while (!a[n][i].empty()) {
            if (a[n][i].front()) v.push_back(inv(n, i, n, 1));
            else v.push_back(inv(n, i, 1, i)), a[1][i].push(0);
            a[n][i].pop();
        }
    }
}

char s[100100];

int main () {
    n = read(), m = read(); int i, j, k;
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) {
        scanf("%s", s + 1); int len = strlen(s + 1);
        for (k = len; k >= 1; k--) a[i][j].push(s[k] - '0');
    }
    solve();
    for (auto i: v) ans.push_back(i);
    v.clear();
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) {
        scanf("%s", s + 1); int len = strlen(s + 1);
        for (k = 1; k <= len; k++) a[i][j].push(s[k] - '0');
    }
    solve();
    reverse(v.begin(), v.end());
    printf("%d\n", v.size() + ans.size());
    for (auto i: ans) printf("%d %d %d %d\n", i.x1, i.y1, i.x2, i.y2);
    for (auto i: v) printf("%d %d %d %d\n", i.x2, i.y2, i.x1, i.y1);
    return 0;
}