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

const int MAXN = 5050;
char a[MAXN]; int n;

int main () {
    scanf("%s", a + 1); n = strlen(a + 1);
    int i, j, ans = 0;
    for (i = 1; i <= n; i++) {
        int cur = 0, hav = 0;
        for (j = i; j <= n; j++) {
            if (a[j] == '(') ++cur;
            if (a[j] == ')') { --cur; }
            if (a[j] == '?') { --cur, ++hav; }
            if (cur < 0) {
                if (hav) --hav, cur += 2;
                else break;
            }
            if (!cur) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}