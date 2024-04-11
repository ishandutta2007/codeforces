//27C
#include<cstdio>
#include<algorithm>

using namespace std;

int n, t1, num[100005], cnt[100005];

int main() {
  scanf("%d", &n);
  if (n < 3) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  t1 = 1; cnt[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (num[i] != num[t1]) {
      num[++t1] = num[i];
      cnt[t1] = i;
    }
  }
  if (t1 < 3) {
    puts("0");
    return 0;
  }
  for (int i = 2; i < t1; i++) {
    if (num[i - 1] < num[i] && num[i] > num[i + 1]) {
      printf("%d\n%d %d %d\n", 3, cnt[i - 1], cnt[i], cnt[i + 1]);
      return 0;
    } else if (num[i - 1] > num[i] && num[i] < num[i + 1]) {
      printf("%d\n%d %d %d\n", 3, cnt[i - 1], cnt[i], cnt[i + 1]);
      return 0;
    }
  }
  puts("0");
  return 0;
}