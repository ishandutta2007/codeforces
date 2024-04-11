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

int main() {
    int T = read(); while (T--) {
        long long n; cin >> n; bool ok = 0;
        for (int i = 15; i <= 20; i++) if (n >= i && (n - i) % 14 == 0) { ok = 1; break; }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}