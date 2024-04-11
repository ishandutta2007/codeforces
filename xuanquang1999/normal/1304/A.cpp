#include <bits/stdc++.h>

using namespace std;

int main() {
    int nTest;
    scanf("%d", &nTest);

    while (nTest--) {
        int x, y, a, b;
        scanf("%d%d%d%d", &x, &y, &a, &b);

        int dist = y - x;
        int k = a + b;

        int ans = (dist%k == 0) ? (dist/k) : -1;
        printf("%d\n", ans);
    }

    return 0;
}