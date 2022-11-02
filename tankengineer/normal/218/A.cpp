#include<cstdio>
#include<algorithm>
using namespace std;

int k, n, a[255];

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n * 2 + 1; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    if (k == 0) continue;
    if (a[i * 2] - 1 > a[i * 2 - 1] && a[i * 2] - 1 > a[i * 2 + 1]) {
      --k;
      --a[i * 2];
    }
  }
  for (int i = 1; i <= n * 2; ++i) printf("%d ", a[i]);
  printf("%d\n", a[n * 2 + 1]);
  return 0;
}