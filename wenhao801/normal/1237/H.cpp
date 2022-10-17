#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n; char s[4040], t[4040];
int a[2020], b[2020];

int ans[5050], top;
int foo(int x) { return (x >= 1 && x <= 2) ? (3 - x) : x; }
void flip(int x) {
    if (x) {
        reverse(a + 1, a + x + 1); ans[++top] = x;
        for (int i = 1; i <= x; i++) a[i] = foo(a[i]);
    }
}

int main() {
    int T = read(); while (T--) {
        top = 0; int i, j, buc[4] = {};
        scanf("%s", s + 1), scanf("%s", t + 1);
        n = strlen(s + 1) >> 1;
        for (i = 1; i <= n; i++) a[i] = (s[i * 2 - 1] - '0') * 2 + s[i * 2] - '0', ++buc[a[i]];
        for (i = 1; i <= n; i++) b[i] = (t[i * 2 - 1] - '0') * 2 + t[i * 2] - '0', --buc[foo(b[i])];
        if (buc[0] || buc[3]) { puts("-1"); continue; }
        int last = 0;
        if (buc[1]) {
            for (i = 1; i <= n; i++) {
                --buc[a[i]], ++buc[3 - a[i]];
                if (!buc[1]) break;
            }
            if (i <= n) flip(i);
            else {
                for (i = 1; i <= n; i++) ++buc[a[i]], --buc[3 - a[i]];
                for (i = 1; i <= n; i++) {
                    ++buc[foo(b[i])], --buc[foo(3 - b[i])];
                    if (!buc[1]) break;
                }
                assert(i <= n); last = i;
                reverse(b + 1, b + i + 1);
                for (j = 1; j <= i; j++) b[j] = foo(b[j]);
            }
        }
        assert(!buc[1] && !buc[2]);
        for (i = n; i >= 1; i--) {
            for (j = n; j > n - i && foo(b[i]) != a[j]; j--);
            assert(j > n - i); flip(j - 1), flip(j);
        }
        printf("%d\n", top + bool(last));
        for (int i = 1; i <= top; i++) cout << ans[i] * 2 << ' ';
        if (last) cout << last * 2 << ' ';
        cout << endl;
    }
    return 0;
}