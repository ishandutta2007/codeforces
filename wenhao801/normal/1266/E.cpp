#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <map>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200;
int n, m, a[MAXN], b[MAXN]; map <int, int> vis[MAXN];

long long cur;
void add(int i, int k) {
    cur -= max(0, a[i] - b[i]);
    b[i] += k;
    cur += max(0, a[i] - b[i]);
}
int main() {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read(), b[i] = 0, cur += a[i];
    m = read(); while (m--) {
        int u = read(), v = read(), k = read();
        if (vis[u][v]) add(vis[u][v], -1);
        vis[u][v] = k;
        if (vis[u][v]) add(vis[u][v], 1);
        cout << cur << endl;
    }
    return 0;
}