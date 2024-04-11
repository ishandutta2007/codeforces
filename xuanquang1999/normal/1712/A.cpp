#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int nTest, n, k, p[MAXN];

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i) scanf("%d", &p[i]);

        int ans = 0;
        for(int i = 1; i <= k; ++i) {
            if (p[i] > k) ++ans;
        }

        printf("%d\n", ans);
    }

    return 0;
}