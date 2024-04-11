#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

bool can[5005000];

int main() {
    int now = 1; bool s = 1;
    can[now] = 1;
    while (now <= int(1e6)) now = now * 2 + 1 + s, s = !s, can[now] = 1;
    int n = read(); putchar((can[n] || can[n - 1]) + '0');
    return 0;
}