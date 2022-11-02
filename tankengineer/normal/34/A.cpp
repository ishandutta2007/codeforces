#include<cstdio>
#include<algorithm>
using namespace std;

int n, a[1005], t1;

int abss(const int i) {return i < 0 ? -i : i;}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  a[n + 1] = a[1];
  t1 = 1;
  for (int i = 2; i <= n; ++i) {
    if (abss(a[i] - a[i + 1]) < abss(a[t1] - a[t1 + 1])) {
      t1 = i;
    }
  }
  printf("%d %d\n", t1, t1 == n ? 1 : t1 + 1);
  return 0;
}