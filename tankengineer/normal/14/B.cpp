//14B
#include<cstdio>
#include<algorithm>

using namespace std;

int n, x, l, r, t1, t2;

int main() {
  scanf("%d %d", &n, &x);
  l = 0; r = 1000;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &t1, &t2);
    if (t1 > t2) swap(t1, t2);
    l = max(l, t1);
    r = min(r, t2);
  }
  if (l > r) {
    puts("-1");
  } else {
    if (x < l) {
      printf("%d\n", l - x);
    } else if (x > r) {
      printf("%d\n", x - r);
    } else {
      puts("0");
    }
  }
  return 0;
}