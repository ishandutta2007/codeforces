#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1010, inf = 1e9 + 7;
int ans[MAXN], n;

#define size(v) (int(v.size()))
using vi = vector <int>;
void ask (vi &v) {
    printf("%d\n", size(v));
    for (auto i: v) printf("%d ", i);
    putchar('\n'); fflush(stdout);
    v.clear(), v.resize(n + 1);
    for (int i = 1; i <= n; i++) v[i] = read();
}

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) ans[i] = inf;
    for (i = 0; i < 10; i++) {
        vector <int> v;
        for (j = 1; j <= n; j++) if ((j >> i) & 1) v.emplace_back(j);
        if (v.empty()) continue;
        ask(v);
        for (j = 1; j <= n; j++) if (!((j >> i) & 1)) ans[j] = min(ans[j], v[j]);
    }
    for (i = 0; i < 10; i++) {
        vector <int> v;
        for (j = 1; j <= n; j++) if (!((j >> i) & 1)) v.emplace_back(j);
        if (v.empty()) continue;
        ask(v);
        for (j = 1; j <= n; j++) if ((j >> i) & 1) ans[j] = min(ans[j], v[j]);
    }
    puts("-1");
    for (i = 1; i <= n; i++) printf("%d ", ans[i]);
    putchar('\n'); fflush(stdout);
    return 0;
}