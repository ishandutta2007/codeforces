#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define Lint long long

inline Lint read () {
    Lint ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

Lint mygcd (Lint x, Lint y) {
    if (x < y) swap(x, y);
    if (x % y == 0) return y;
    else return mygcd(y, x % y);
}

signed main () {
    int n = read();
    Lint x = read();
    Lint ans = x;
    Lint i, j;
    for (i = 1; i < n; i++) {
        if (ans == 1) break;
        x = read();
        ans = mygcd(ans, x);
    }
    if (ans == 1) puts("1");
    else {
        Lint out = 0;
        for (i = 1; i <= sqrt(ans); i++) {
            if (ans % i == 0) out += 2;
        }
        if ((Lint)(sqrt(ans)) * (Lint)(sqrt(ans)) == ans) out--;
        cout << out << endl;
    }
    return 0;
}