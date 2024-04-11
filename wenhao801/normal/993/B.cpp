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

#define pii pair<int, int>
int n, m; pii a[13], b[13];
bool ans_they = 1, ans_you[12];

int judge (pii x, pii y) {
    bool f1 = x.first == y.first, f2 = x.second == y.first, f3 = x.first == y.second, f4 = x.second == y.second;
    if (f1 + f2 + f3 + f4 != 1) return -1;
        if (f1 || f3) return x.first; else return x.second;
}

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) {
        int x = read(), y =read(); if (x > y) swap(x, y);
        a[i] = make_pair(x, y);
    }
    for (i = 1; i <= m; i++) {
        int x = read(),y  = read(); if (x > y) swap(x, y);
        b[i] = make_pair(x, y);
    }
    for (int p = 1; p <= n; p++) for (int q = 1; q <= m; q++) {
        int num = judge(a[p], b[q]);
        if (num == -1) continue;
        // printf("! %d: %d %d %d %d\n", num, a[p].first, a[p].second, b[q].first, b[q].second);
        bool f1 = 0, f2 = 0;
        for (i = 1; i <= m; i++) {
            int num2 = judge(a[p], b[i]);
            if (num2 == -1) continue;
            f1 |= num2 == a[p].first; f2 |= num2 == a[p].second;
        }
        if (!(f1 ^ f2))  {
            puts("-1");
            return 0;
        }
        f1 = f2 = 0;
        for (i = 1; i <= n; i++) {
            int num2 = judge(b[q], a[i]);
            if (num2 == -1) continue;
            f1 |= num2 == b[q].first; f2 |= num2 == b[q].second;
        }
        if (!(f1 ^ f2))  {
            puts("-1");
            return 0;
        }
        ans_you[num] = 1;
    }
    int s =0 ; for (i = 1; i <= 9; i++) s += ans_you[i];
    if (s == 1) { for (i = 1; i <= 9; i++) if (ans_you[i]) cout << i << endl; } else puts("0");
    return 0;
}