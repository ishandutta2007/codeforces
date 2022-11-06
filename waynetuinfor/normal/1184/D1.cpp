#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m, t; scanf("%d%d%d%d", &n, &k, &m, &t);
    int l = n, p = k;

    while (t--) {
        int x, y; scanf("%d%d", &x, &y);
        if (x == 1) {
            ++l;
            if (y <= p) ++p;
        } else {
            if (y < p) {
                l -= y;
                p -= y;
            } else {
                l = y;
            }
        }
        printf("%d %d\n", l, p);
    }
    return 0;
}