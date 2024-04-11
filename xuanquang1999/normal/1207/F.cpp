#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;
const int MAGIC = 707;

int q, a[MAXN], res[MAGIC][MAGIC];

int main() {
    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);

        if (t == 1) {
            a[x] += y;
            for(int q = 1; q < MAGIC; ++q)
                res[x%q][q] += y;
        } else {
            int ans;
            if (x < MAGIC)
                ans = res[y%x][x];
            else {
                ans = 0;
                for(int i = y%x; i < MAXN; i += x)
                    ans += a[i];
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}