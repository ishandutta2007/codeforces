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

int main () {
    int q = read();
    while (q--) {
        int n = read();
        int i, j;
        int s = 0;
        for (i = 1; i <= n; i++)
            s += read();
        j = s / n;
        if (j * n == s) cout << j << endl;
        else cout << j + 1 << endl;
    }
    return 0;
}