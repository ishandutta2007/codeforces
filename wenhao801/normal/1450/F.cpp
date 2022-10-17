#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100100;
int n, a[MAXN];
vector <int> v[MAXN], cur; int top, b1[MAXN], b2[MAXN], b[MAXN];
void clear() {
    for (int i = 1; i <= n; i++) v[i].clear(), b1[i] = b2[i] = b[i] = 0;
    cur.clear(), top = 0;
}

int main() {
    int T = read(); while (T--) {
        n = read(); int i,j ;
        for (i = 1; i <= n; i++) a[i] = read(), ++b[a[i]];
        for (i = 1; i <= n; i++) if (b[i] > n - b[i] + 1) { puts("-1"); break; }
        if (i <= n) { clear(); continue; }
        for (i = 1; i <= n; i++) {
            if (!cur.empty() && cur.back() == a[i]) v[++top] = cur, cur.clear();
            cur.push_back(a[i]);
        }
        v[++top] = cur, cur.clear();
        for (i = 1; i <= top; i++) {
            if (v[i][0] == v[i].back()) ++b2[v[i][0]];
            else ++b1[v[i][0]], ++b1[v[i].back()];
        }
        int ans = top - 1;
        for (i = 1; i <= n; i++) if (b2[i] > top - b2[i] - b1[i] + 1) {
            ans += b2[i] - (top - b2[i] - b1[i] + 1);
            break;
        }
        printf("%d\n", ans);
        clear();
    }
    return 0;
}