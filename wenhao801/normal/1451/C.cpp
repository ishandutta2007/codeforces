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

int n, k, buc[33][2];
char tmp[1001000];

int main () {
    int T = read();
    while (T--) {
        int i, j;
        n = read(), k = read();
        for (i = 0; i < 26; i++) buc[i][0] =buc[i][1] = 0;
        scanf("%s", tmp + 1);
        for (i = 1; i <= n; i++) ++buc[tmp[i] - 'a'][0];
        scanf("%s", tmp + 1);
        for (i = 1; i <= n; i++) ++buc[tmp[i] - 'a'][1];
        bool fail  = 0;
        for (i = 0; i < 25; i++) {
            if (buc[i][0] < buc[i][1] || buc[i][0] % k != buc[i][1] % k) fail = 1;
            else buc[i + 1][0] += buc[i][0] - buc[i][1];
        }
        if (fail || buc[25][0] != buc[25][1]) puts("NO");
        else puts("YES");
    }
    return 0;
}