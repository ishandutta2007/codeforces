#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200;
vector <int> E[MAXN];
int n, l[MAXN], r[MAXN];

long long s[MAXN]; int cost = 0;
void dfs (int x) {
    for (auto i: E[x]) dfs(i), s[x] += s[i];
    if (s[x] < l[x]) ++cost, s[x] = r[x];
    if (s[x] > r[x]) s[x] = r[x];
}

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j;
        for (i = 2; i <= n; i++) {
            j = read(); E[j].push_back(i);
        }
        for (i = 1; i <= n; i++) l[i] = read(), r[i] = read();
        dfs(1);
        printf("%d\n", cost); cost = 0;
        for (i = 1; i <= n; i++) s[i] = 0, E[i].clear();
    }
    return 0;
}