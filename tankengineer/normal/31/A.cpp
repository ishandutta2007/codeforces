#include<cstdio>
#include<algorithm>
using namespace std;

int n, a[105];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        if (i != j && j != k && i != k && a[i] == a[j] + a[k]) {
          printf("%d %d %d\n", i, j, k);
          return 0;
        }
      }
    }
  }
  puts("-1");
  return 0;
}