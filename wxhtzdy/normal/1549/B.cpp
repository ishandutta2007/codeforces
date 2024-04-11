#include <stdio.h>

#define N       200005

int main() {
        static char aa[N], bb[N];
        int t;

        scanf("%d", &t);
        while (t--) {
                int n, i, ans;

                scanf("%d\n%s\n%s", &n, &aa, &bb);
                ans = 0;
                for (i = 0; i < n; i++) {
                        if (bb[i] == '1') {
                                if (i > 0 && aa[i - 1] == '1')
                                        ans++, aa[i - 1] = '0';
                                else {
                                        if (aa[i] == '0') ans++;
                                        else if (i + 1 < n && aa[i + 1] == '1')
                                                ans++, aa[i + 1] = '0';
                                }
                        }
                }
                printf("%d\n", ans);
        }
        return 0;
}