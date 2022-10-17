#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline long long read () {
    long long ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int main () {
    int T = read();
    while (T--) {
        long long n = read(), k = read();
        int i, j;
        
        cout << (k / n) * (k / n) * (n - (k % n)) + ((k % n)) * (k / n + 1) * (k / n + 1) << endl;
    }
    return 0;
}