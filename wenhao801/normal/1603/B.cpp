#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <random>

using namespace std;

mt19937 RND (time(NULL));
int rnd (int l, int r) {
    return RND() % (r - l + 1) + l;
}

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

int calc (int x, int y) {
    if (x == y) return x;
    else if (x < y) {
        if (2 * x >= y) return (x + y) >> 1;
        int tmp = y % x;
        return y - (tmp >> 1);
    }
    else return (x + y);
}

int main () {
    int T = read();
    while (T--) {
       int x = read(), y = read();
       cout << calc(x, y) << endl; 
        // int x = rnd(1, 50), y = rnd(1, 50);
        // x *= 2, y *= 2; int n = calc(x, y);
        // if (n % x != y % n) { printf("! %d %d\n", x, y); return 0; }
    }
    return 0;
}