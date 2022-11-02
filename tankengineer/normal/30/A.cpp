#include<cstdio>
#include<algorithm>
using namespace std;

int a, b, n;

long long llsabs(long long i) {return i > 0 ? i : -i;}

bool test(const int x) {
  long long t1 = a, t2 = b;
  for (int i = 1; i <= n; ++i) {
    t1 = t1 * x;
    if (llsabs(t1) > llsabs(t2)) return false;
  }
  return t1 == t2;
}

int main() {
  scanf("%d %d %d", &a, &b, &n);
  for (int i = -2000; i <= 2000; ++i) {
    if (test(i)) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("No solution");
  return 0;
}