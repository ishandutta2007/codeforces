#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

bool a[1010]; int s = 0;

int main() {
    int n = read(), i, j, id, ans = 0;
    if (n <= 3) { puts("0"); return 0; };
    for (i = 2; i + i <= n; i++) {
        int tmp = (n / i) * (i - 1) + max(0, n % i - 1) - (i - 1);
        if (ans < tmp) ans = tmp, id = i;
    }
    while (s != ans) {
        vector <int> op;
        for (i = 1; i <= n; i++) {
            bool val = i % id && i != n;
            if (val && !a[i]) op.push_back(i), ++s, a[i] = 1;
        }
        printf("%d ", op.size()); for (auto i: op) printf("%d ", i); putchar('\n');
        fflush(stdout);

        int x = read();
        for (i = 1; i <= op.size(); i++) {
            int now = (x + i - 1 - 1) % n + 1;
            if (a[now]) --s, a[now] = 0;
        }
    }
    puts("0");
    return 0;
}