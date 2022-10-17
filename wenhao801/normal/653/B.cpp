#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n, q; long long f[55][55], to[55][55];

int main () {
    n = read(), q = read(); int i, j;
    for (i = 1; i <= q; i++) {
        char s[5], t[5]; cin >> s >> t;
        to[t[0] - 'a'][s[0] - 'a']++;
    }
    f[1][0] = 1;
    for (i = 1; i < n; i++) {
        for (j = 0; j < 6; j++) for (int k = 0; k < 6; k++)
            f[i + 1][k] += to[j][k] * f[i][j];
    }
    long long ans = 0; for (i = 0; i < 6; i++) ans += f[n][i];
    cout << ans;
    return 0;
}