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

const int inf = 1e9 + 7;
char s[100100];
int main () {
    int T = read();
    while (T--) {
        scanf("%s", s + 1); int n = strlen(s + 1);
        int i, j;
        int cnt = 0; s[0] = '1';
        for (i = 1; i <= n; i++) {
            if (s[i] == '0' && s[i - 1] != '0') ++cnt;
        }
        if (cnt <= 1) cout << cnt << endl; else puts("2");
    }
    return 0;
}