#include<cstdio>
#include<algorithm>
using namespace std;

int n, r, ans, t1, t2, t3, a, b;
char anst[1000005];

int check(const int x, const int y) {
  a = x; b = y;
  int cnt = n, cot = 0, t1, t2, t3;
  while (b != 0 && cnt >= 0) {
    t1 = a / b;
    t2 = a % b;
    cnt -= t1;
    if (t1 > 0) cot += t1 - 1;
    a = b;
    b = t2;
  }
  --cot;
  if (cnt != 0 || a != 1) return n; else return cot;
}

int main() {
  scanf("%d %d", &n, &r);
  ans = n;
  if (n == 1 && r == 1) {
    ans = 0;
    t3 = 1;
  }
  for (int i = 1; i < r; ++i) {
    t1 = check(r, i); t2 = check(i, r);
    if (ans > t1) {
      ans = t1;
      t3 = i;
    }
    if (ans > t2) {
      ans = t2;
      t3 = -i;
    }
  }
  if (ans == n) {
    printf("IMPOSSIBLE\n");
    return 0;
  }
  printf("%d\n", ans);
  if (t3 < 0) {
    a = -t3;
    b = r;
  } else {
    a = r;
    b = t3;
  }
  for (int i = n - 1; i >= 0; --i) {
    //printf("%d %d\n", a, b);
    if (a >= b) {
      anst[i] = 'T';
      a -= b;
    } else {
      anst[i] = 'B';
      b -= a;
    }
  }
  if (anst[0] == anst[1]) {
    for (int i = 1; i < n; ++i) {
      if (anst[i] == 'T') anst[i] = 'B'; else anst[i] = 'T';
    }
  }
  puts(anst);
  return 0;
}