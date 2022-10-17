#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n, m;
int a[1010], b[1010];
bool ba[1010], bb[1010];

int main () {
    n = read();
    int i, j;
    for (i = 1; i <= n; i++) {
        a[i] = read();
        ba[a[i]] = true;
    }
    m = read();
    for (i = 1; i <= m; i++) {
        b[i] = read();
        bb[b[i]] = true;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (!ba[a[i] + b[j]] && !bb[a[i] + b[j]]) {
                cout << a[i] << ' ' << b[j] << endl;
                return 0;
            }
        }
    }
    return 0;
}