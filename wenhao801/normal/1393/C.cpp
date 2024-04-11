#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN= 100010;
int n, s;
int  b[MAXN];
bool cmp (int x, int y) { return x > y; }

struct pr { int num, left; bool operator < (const pr &x) const { return x.left > left; } };
priority_queue <pr> q;
int a[MAXN];
bool vis[MAXN]; int bibo[MAXN];
bool check (int x) {
    while (!q.empty()) q.pop();
    int i, j;
    for (i = 1; i <= n; i++) q.push({i, b[i]}), a[i] = b[i], vis[i] = false;
    for (i = 1; i <= s; i++) bibo[i] = 0;
    for (i = 1; i <= s; i++) {
        if (i - x - 1 >= 1 && a[bibo[i - x - 1]]) q.push({bibo[i - x - 1], a[bibo[i - x - 1]]}), vis[bibo[i - x - 1]] = false; 
        if (q.empty()) return false;
        int fr = q.top().num; --a[fr], bibo[i] = fr, vis[fr] = true; q.pop();
    }
    return true;
}
int main () {
    int T = read();
    while (T--) {
        n = read(); s = 0;
        int i, j;
        for (i = 1; i <= n; i++) ++b[read()];
        sort(b + 1, b + n + 1, cmp);
        for (i = 1; i <= n &&b[i]; i++) s += b[i]; n = i - 1;
        int L = 0, R = n, ans;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (check(mid)) ans = mid, L = mid + 1;
            else R = mid - 1;
        }
        printf("%d\n", ans);
        for (i = 1; i <= n; i++) b[i] = 0;
    }
    return 0;
}