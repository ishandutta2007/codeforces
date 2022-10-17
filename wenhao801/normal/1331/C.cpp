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

int a[1000];

int main () {
    int n = read();
    int i, j;
    for (i = 0; i < 6; i++) a[i] = n & 1, n >>= 1;
    swap(a[0], a[4]), swap(a[2], a[3]);
    for (i = 0, j = 0; i < 6; i++) j += a[i] * (1 << i);
    cout << j;
    return 0;
}