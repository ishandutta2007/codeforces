#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int nTest, n, a[MAXN];

int main() {
    scanf("%d", &nTest);
    while (nTest--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);

        int cnt0 = 0;
        for(int i = 0; i < n; ++i)
            cnt0 += a[i] == 0;

        int k = n/2;
        if (k%2 == 1 && cnt0 < n/2)
            ++k;

        printf("%d\n", k);
        for(int i = 0; i < k; ++i)
            printf("%d ", (cnt0 < n/2) ? 1 : 0);
        puts("");
    }

    return 0;
}