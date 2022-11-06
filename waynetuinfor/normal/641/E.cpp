#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

const int maxn = 1e9 + 1;

struct fenwick {
    unordered_map<int, unordered_map<int, int>> arr;
    inline int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) ++arr[i][v];
    }
    void del(int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) --arr[i][v];
    }
    int qry(int x, int v) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += arr[i][v];
        return ret;
    }
} bit;

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

int main() {
    int n; rit(n);
    while (n--) {
        int a, t, x; rit(a, t, x);
        if (a == 1) bit.add(t, x);
        if (a == 2) bit.del(t, x);
        if (a == 3) printf("%d\n", bit.qry(t, x));
    }
    return 0;
}