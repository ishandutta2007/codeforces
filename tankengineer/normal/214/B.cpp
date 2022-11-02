#include<cstdio>
#include<algorithm>
using namespace std;

int n, t1, sum, cnt[10];

int main() {
  scanf("%d", &n);
  sum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t1);
    cnt[t1]++;
    sum += t1;
  }
  if (cnt[0] == 0) {
    printf("-1\n");
    return 0;
  }
  if (sum % 3 != 0) {
    for (int i = 0; i <= 9; ++i) {
      if (cnt[i] && (sum - i) % 3 == 0) {
        sum -= i;
        --cnt[i];
        break;
      }
    }
    if (sum % 3 != 0) {
      for (int i = 0; i <= 18; ++i) {
        for (int j = 0; j <= 9; ++j) {
          if (i - j > 9 || i - j < 0) continue;
          if (cnt[i - j] && cnt[j] && (sum - i) % 3 == 0) {
            if (i == j + j && cnt[j] < 2) continue;
            sum -= i;
            --cnt[i - j];
            --cnt[j];
            break;
          }
        }
        if (sum % 3 == 0) break;
      }
    }
  }
  if (sum == 0 && cnt[0]) {
    printf("0\n");
    return 0;
  }
  if (sum == 0 && cnt[0] == 0) {
    printf("-1\n");
    return 0;
  }
  for (int i = 9; i >= 0; --i) {
    for (int j = cnt[i]; j > 0; --j) {
      printf("%d", i);
    }
  }
  printf("\n");
  return 0;
}