#include <stdio.h>

#define N       300005

int main() {
        int t;

        scanf("%d", &t);
        while (t--) {
                static char aa[N], bb[N];
                static int can[N];
                int n, i, x, y, d, ans;

                scanf("%d%s%s", &n, aa, bb);
                x = 0, y = 0;
                for (i = 0; i < n; i++) {
                        if (aa[i] == '0') x++;
                        else y++;
                        can[i] = (x == y ? 1 : 0);
                }
                d = 0, ans = 1;
                for (i = n - 1; i >= 0; i--) {
                        aa[i] = (char) ((aa[i] - '0' + d) % 2 + '0');
                        if (aa[i] != bb[i]) {
                                if (can[i] == 0) ans = 0;
                                else d++;
                        }
                }
                if (ans == 0) printf("NO\n");
                else printf("YES\n");
        }
}