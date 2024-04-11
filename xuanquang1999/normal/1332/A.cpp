#include <bits/stdc++.h>

using namespace std;

bool solve(int a, int b, int l, int x, int r) {
    int destX = x - a + b;
    if (destX < l || destX > r)
        return false;
    if (a + b > 0 && l == r)
        return false;
    return true;
}

int main() {
    int nTest;
    scanf("%d", &nTest);

    while (nTest--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int x, y, x1, y1, x2, y2;
        scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);

        bool ans = solve(a, b, x1, x, x2) && solve(c, d, y1, y, y2);
        puts(ans ? "Yes" : "No");        
    }

    return 0;
}