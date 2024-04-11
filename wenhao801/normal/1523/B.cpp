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
    int T = read();
    while (T--) {
        int n = read(); n >>= 1; cout << n * 6 << endl;
        for (int j = 1; j <= n; j++) {
            int x = read(), y = read();
            for (int i = 1; i <= 3; i++) printf("1 %d %d\n2 %d %d\n", j * 2 - 1, j * 2, j * 2 - 1, j * 2);
        }
    }
    return 0;
}