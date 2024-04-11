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

int n;
char a[1001000];

int main () {
    n = read();
    scanf("%s", a + 1);
    int i, j;
    int ans = 0;
    bool f = false;
    for (i = 1, j = 0; i <= n; i++) {
        if (a[i] == '(') j++; else j--;
        if (j < 0) ans++, f = true;
        if (j == 0 && f) ans++, f = false;
    }
    if (j != 0) puts("-1");
    else cout << ans << endl;
    return 0;
}