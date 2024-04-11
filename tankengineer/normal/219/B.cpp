#include<cstdio>
#include<algorithm>
using namespace std;

long long oct[19], p, k, ans, tmp;

int main() {
  oct[0] = 1;
  for (int i = 1; i <= 18; ++i) oct[i] = oct[i - 1] * 10;
  scanf("%I64d %I64d", &p, &k);
  ans = p;
  long long t1 = p;
  int t2 = 0, t3 = 0;
  while (t1 % 10 == 9) {
    ++t2;
    t1 /= 10;
  }
  t1 = p;
  while (t1) {
    ++t3;
    t1 /= 10;
  }
  ans = p;
  for (int i = t2 + 1; i < t3; ++i) {
    tmp = oct[i] - 1 + (p / oct[i] - 1) * oct[i];
    //printf("%d %I64d\n", i, tmp);
    if (tmp + k >= p) {
      ans = tmp;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}