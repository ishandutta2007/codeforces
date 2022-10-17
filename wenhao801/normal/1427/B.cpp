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

char a[100100];
vector <int> len;

int main() {
    int T = read(); while (T--) {
        int n = read(), K = read();
        scanf("%s", a + 1); int i, j, s = 0;
        bool fir = 1;
        for (i = 1; i <= n; i++) {
            if (a[i] == 'W') s += 2 - fir, fir = 0;
            else {
                fir = 1;
                for (j = i; j <= n && a[j] == 'L'; j++);
                if (i != 1 && j <= n) len.push_back(j - i);
                i = j - 1;
            }
        }
        if (!s) {
            if (!K) puts("0");
            else printf("%d\n", min(1 + 2 * (K - 1), 2 * n - 1));
            continue;
        }
        sort(len.begin(), len.end());
        for (auto i: len) {
            if (K >= i) s += 2 * i + 1, K -= i;
        }
        s += K * 2;
        printf("%d\n", min(s, 2 * n - 1));
        len.clear();
    }
    return 0;
}