#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
#define int long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}
 
char a[1001000] = {};
signed main () {
    int Q = read();
    while (Q--) {
        int n = read(), k = read();
        scanf("%s", a + 1);
        int i, j;
        int l = 0, r = 0;
        for (i = 1; i <= n; i++) {
            if (k == 0) break;
            if (a[i] == '1') r++;
            if (a[i] == '0') {
                if (r != l) {
                    if (k < i - l - 1) {
                        for (j = i; j > l + 1 && k; j--) k--, swap(a[j], a[j -1]);
                        break;
                    }
                    else k -= i - l - 1, swap(a[i], a[l + 1]), l++;
                }
                else l++;
                r++;
            }
        }
        printf("%s\n", a + 1);
    }
    return 0;
}