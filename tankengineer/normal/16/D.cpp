//16D
#include<cstdio>
#include<cstring>

int ans, prev, n, h, m, t, cnt;
char ap;

int main() {
  ans = 1; prev = -1;
  scanf("%d", &n);
  getchar();
  while (n--) {
    scanf("[%d:%d %c", &h, &m, &ap);
    if (h == 12) h = 0;
    if (ap == 'p') h += 12;
    while (getchar() != '\n');
    t = h * 60 + m;
    if (t == prev) {
      if (cnt <= 9) {
        cnt++;
      } else {
        cnt = 1;
        ans++;
      }
    } else {
      if (t < prev) {
        ans++;
      }
      cnt = 1;
    }
    prev = t;
  }
  printf("%d\n", ans);
  return 0;
}