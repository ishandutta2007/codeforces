#include <stdio.h>

int main() {
        static char name[15];
        int n, ans;

        scanf("%d", &n);
        ans = 0;
        while (n--) {
                int before, after;

                scanf("%s%d%d", name, &before, &after);
                if (before >= 2400 && after > before)
                        ans = 1;
        }
        if (ans == 0) printf("NO");
        else printf("YES");
        return 0;
}