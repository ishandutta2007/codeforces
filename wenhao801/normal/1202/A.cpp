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

const int MAXN = 100100;

char a[MAXN], b[MAXN];

int main () {
    int T = read();
    while (T--) {
        scanf("%s", a);
        scanf("%s", b);
        int la = strlen(a), lb = strlen(b);
        int i, j;
        for (i = lb - 1; i >= 0; i--) {
            if (b[i] == '1') {
                for (j = la - 1 - (lb - 1 - i); j >= 0; j--) {
                    if (a[j] == '1') {
                        printf("%d\n", la - 1 - (lb - 1 - i) - j);
                        break;
                    }
                }
                break;
            }
        }
    }
    return 0;
}