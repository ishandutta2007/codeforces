//26E
#include<cstdio>
#include<algorithm>

using namespace std;

int n, w, sum, p_one, t1, cnt[105], ptf[105], tmp;

int main() {
  scanf("%d %d", &n, &w);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cnt[i]);
      if (cnt[i] == 1) p_one = i;
        sum += cnt[i];
    }
    if (w < 1 || w > sum || n == 1 && cnt[1] != w || !p_one && w == 1) {
        puts("No");
        return 0;
    }
    if (n == 1) {
        puts("Yes");
      for (int i = 1; i <= 2 * w - 1; i++) printf("1 ");
        printf("1\n"); 
    } else if (w == 1) {
      puts("Yes");
        printf("%d ", p_one);
        for (int i = 1; i <= n; i++) {
            if (i == p_one) continue;
            for (int j = 1; j <= cnt[i] * 2; j++) {
                printf("%d ", i);
            }
        }
        printf("%d\n", p_one);
    } else {
        w -= 2;
      cnt[1]--; cnt[2]--;
        t1 = 1;
        while (w) {
          tmp = min(w, cnt[t1]);
            ptf[t1] = tmp;
            cnt[t1] -= tmp;
            w -= tmp;
            if (!cnt[t1]) t1++;
        }
        puts("Yes");
        printf("1 ");
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= cnt[i] * 2; j++) {
                printf("%d ", i);
            }
        }
        printf("1 2 ");
        for (int i = 1; i <= cnt[1] * 2; i++) {
            printf("1 ");
        }
        printf("2");
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= ptf[i] * 2; j++) {
                printf(" %d", i);
            }
        }
        printf("\n");
    }
    return 0;
}