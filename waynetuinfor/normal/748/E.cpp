#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

inline int gtx() {
    const int N = 1048576;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char __c = 0; bool flag = false;
    while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
    __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
    while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

const int maxn = 1e6 + 10, inf = 1e7 + 1;
int a[maxn], n, k, piece[inf];

void init(int now) {
    for (int i = 0; i < inf; ++i) {
        if (i < now) piece[i] = 0;
        else piece[i] = 1;
        piece[i] = max(piece[i], piece[i / 2] + piece[i - i / 2]);
    }
}

bool check(int now) {
    init(now);
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += piece[a[i]];
        if (ret >= k) return true;
    }
    return false;
}

int main() {
    rit(n, k);
    for (int i = 0; i < n; ++i) rit(a[i]);
    int d = 1, ans = 0; while (d < inf) d <<= 1;
    while (d >>= 1) if (ans + d < inf) if (check(ans + d)) ans += d;
    if (ans == 0) ans = -1;
    printf("%d\n", ans);
    return 0;
}