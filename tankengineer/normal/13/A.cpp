//CF 13A
#include<cstdio>
#include<algorithm>

using namespace std;

int n, t1, t2, t3;

int gcd(int x, int y) {
  int z = (x % y);
  while (z != 0) {
    x = y;
    y = z;
    z = (x % y);
  }
  return y;
}

int main() {
  scanf("%d", &n);
  for (int i = 2; i < n; i++) {
    t3 = n;
    while (t3) {
      t1 = t1 + t3 % i;
      t3 /= i;
    }
    t2++;
  }
  t3 = gcd(t1, t2);
  t1 /= t3;
  t2 /= t3;
  printf("%d/%d\n", t1, t2);
  return 0;
}