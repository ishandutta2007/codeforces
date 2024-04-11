#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

int main () {
    int T = read();
    while (T--) {
        int n = read();
        if (n == 1) puts("1");
        else if (n == 2) puts("2");
        else if (n & 1) cout << (n - 1) / 2 + 1 << endl;
        else cout << (n - 2) / 2 + 2<< endl;
    }
    return 0;
}