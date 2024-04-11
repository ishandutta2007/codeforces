//a
#include<cstdio>
#include<algorithm>
using namespace std;

int a, b, c, sum;

int main() {
  scanf("%d %d %d", &a, &b, &c);
  int t1 = a;
  sum = a;
  for (int i = 2; i <= min(b, c); ++i) {
    ++a;
    sum += a;
  }
  for (int i = min(b, c) + 1; i <= max(b, c); ++i) sum += a;
  for (int i = max(b, c) + 1; i <= b + c - 1; ++i) {
    --a;
    sum += a;
  }
  if (a != t1) puts("ERRPR");
  printf("%d\n", sum);
  return 0;
}