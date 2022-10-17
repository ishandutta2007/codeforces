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

int n, m; vector <int> a[200200];

int main () {
    int i, j; n = read(), m = read();
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) {
        int x = read();
        a[x * 2 - 1].push_back(i), a[x * 2].push_back(j);
    }
    long long ans = 0;
    for (i = 1; i <= 200000; i++) {
        sort(a[i].begin(), a[i].end()); int s = a[i].size();
        for (int j = 0; j < s; j++) {
            ans += 1ll * a[i][j] * (j - (s - j - 1));
        }
    }
    printf("%lld\n", ans);
    return 0;
}