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
    int T = read(); while (T--) {
        int n = read(); long long las = 0;
        bool no = 0, done = 0;
        for (int i = 1; i <= n; i++) {
            int x = read();
            las += x;
            if (las < 0) no = 1;
            if (done && las) no = 1;
            if (!las) done = 1;
        }
        if (!done) no = 1;
        puts(no ? "No" : "Yes");
    }
    return 0;
}