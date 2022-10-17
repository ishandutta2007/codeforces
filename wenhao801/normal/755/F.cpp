#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1001000;
int n, K, p[MAXN], buc[MAXN];
vector <int> cur;

bitset <MAXN> bs;

int main () {
    n = read(), K = read(); int i, j, k;
    for (i = 1; i <= n; i++) p[i] = read();
    int out[3] = {};
    for (i = 1; i <= n; i++) if (p[i]) {
        int tmp = 0;
        for (j = i; p[j]; k = p[j], p[j] = 0, j = k) ++tmp;
        ++buc[tmp];
        out[2] += tmp >> 1, out[1] += tmp & 1;
    }
    for (i = 1; i <= n; i++) if (buc[i]) {
        for (j = 0; (1 << j) <= buc[i]; j++) cur.push_back((1 << j) * i), buc[i] -= 1 << j;
        if (buc[i]) cur.push_back(buc[i] * i);
    }
    bs[0] = 1;
    for (auto i: cur) bs |= bs << i;
    printf("%d %d\n", K + 1 - bs[K], K > out[2] ? (out[2] * 2 + min(out[1], K - out[2])) : (K << 1));
    return 0;
}