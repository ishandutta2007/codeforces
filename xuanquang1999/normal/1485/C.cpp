#include <bits/stdc++.h>

using namespace std;

const int oo = (int)1e9 + 7;

int main() {
    int nTest;
    scanf("%d", &nTest);

    while (nTest--) {
        int x, y;
        scanf("%d%d", &x, &y);

        long long ans = 0;
        for(int d = 1; d <= sqrt(x); ++d) {
            // (a, b): (k*d, k-1) with k >= d+2
            int r = min(x/d, y+1);
            int l = d + 2;
//            printf("%d %d %d\n", d, l, r);
            ans += max(r-l+1, 0);
        }

        printf("%lld\n", ans);
    }

    return 0;
}