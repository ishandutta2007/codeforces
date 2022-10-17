#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
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

const int MAXN = 400400;
int n; bool sp[MAXN];
vector <int> E[MAXN];

queue <int> q, q2; int h[MAXN];

int b[MAXN], top, d[MAXN], res[MAXN];

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) {
        sp[i] = read();
        if (!sp[i]) h[i] = -1; else h[i] = 0, q.push(i);
    }
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        E[u].push_back(v), E[v].push_back(u);
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto i: E[x]) if (h[i] == -1) h[i] = h[x] + 1, q.push(i);
    }
    for (i = 1; i <= n; i++) res[i] = h[i];
    for (i = 1; i <= n; i++) for (auto j: E[i]) if (h[i] == h[j]) b[++top] = h[i];
    sort(b + 1, b + top + 1); top = unique(b + 1, b + top + 1) - b - 1;
    for (i = top; i >= 1; i--) {
        for (j = 1; j <= n; j++) d[j] = 1e9 + 7;
        for (j = 1; j <= n; j++) if (h[j] == b[i]) {
            bool hav = 0;
            for (auto k: E[j]) if (h[k] == b[i]) hav = 1;
            if (hav) q.push(j), d[j] = 0;
        }
        while (!q.empty() || !q2.empty()) {
            int x;
            if (q2.empty() || (!q.empty() && !q2.empty() && d[q.front()] < d[q2.front()])) x = q.front(), q.pop();
            else x = q2.front(), q2.pop();
            for (auto i: E[x]) {
                if (h[i] > h[x]) {
                    if (d[i] > max(0, d[x] - 1)) d[i] = max(0, d[x] - 1), q.push(i);
                }
                else if (h[i] == h[x]) {
                    if (d[i] > d[x] + 1) d[i] = d[x] + 1, q2.push(i);
                }
            }
        }
        for (j = 1; j <= n; j++) if (!d[j]) res[j] = min(res[j], b[i]);
    }
    for (i = 1; i <= n; i++) printf("%d ", 2 * h[i] - res[i]);
    return 0;
}