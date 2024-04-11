#include <bits/stdc++.h>

using namespace std;

const int N = 6e3;
const int M = 1e7 + 100;

int n, k, tt, x, a[N], used[M];

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        used[a[i]] = 1;
    }
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &x);
        int ans = k + 1;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j <= i; j++) {
                if (i + j > k) break;
                for (int e = 0; e < n; e++) {
                    if (a[e] * i > x) break;
                    int cur = x - a[e] * i;
                    if (cur == 0) {
                        ans = min(ans, i + j);
                        continue;
                    }
                    if (j == 0) continue;
                    if (cur % j != 0) continue;
                    int ncur = cur / j;        
                    if (ncur >= M) continue;
                    if ((cur != 0) && (!used[ncur])) continue;
                    ans = min(ans, i + j);
                }
            }
        }
        if (ans > k) ans = -1;
        printf("%d\n", ans);
    }
}