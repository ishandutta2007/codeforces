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
char a[100100] = {};
int len;
int l[100100], r[100010];
int cnt = 0;
int main () {
    int T = read();
    while (T-- ) {
        scanf("%s", a + 1);
        len = strlen(a + 1);
        int i, j;
        bool f = false;
        cnt = 0;
        for (i = 1; i <= len; i++) {
            if (a[i] == '?' && a[i - 1] != '?') l[++cnt] = i;
            if (a[i] == '?' && a[i + 1] != '?') r[cnt] = i;
            if (a[i] != '?' && a[i - 1] == a[i] && i >= 2) { f = true; break; }
        }
        if (f) { puts("-1"); continue; }
        char t;
        char rua;
        for (i = 1; i <= cnt; i++) {
            if (a[l[i] - 1] == 'a' || (a[r[i] + 1] == 'a' && r[i] != len)) {
                if (a[l[i] - 1] == 'b' || (a[r[i] + 1] == 'b' && r[i] != len))
                    t = 'c';
                else t = 'b';
            }
            else t = 'a';
            if ((a[r[i] + 1] == 'a' && r[i] != len) || t == 'a') {
                if ((a[r[i] + 1] == 'b' && r[i] != len) || t == 'b')
                    rua = 'c';
                else rua = 'b';
            }
            else rua = 'a';
            a[l[i]] = t;
            for (j = l[i] + 1; j <= r[i]; j++) {
                if (a[j - 1] == t) a[j] = rua;
                else a[j] = t;
            }
        }
        for (i = 1; i <= len; i++) printf("%c", a[i]); putchar('\n');
    }
    return 0;
}