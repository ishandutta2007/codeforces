#include <bits/stdc++.h>
using namespace std;

int query(int x, int y) {
    printf("%d %d\n", x, y);
    fflush(stdout);
    static char s[20];
    scanf("%s", s);
    return s[0] == 'b';
}

const int y = 7122;

int main() {
    int n; scanf("%d", &n);
    int l = 0, r = 1000000000;
    int p = query(0, y);
    for (int i = 0; i < n - 1; ++i) {
        int m = (l + r) >> 1;
        int q = query(m, y);
        if (q == p) l = m;
        else r = m;
    }
    printf("%d %d %d %d\n", l, 0, l + 1, 1000000000);
    fflush(stdout);
    return 0;
}