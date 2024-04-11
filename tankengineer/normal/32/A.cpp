#include<cstdio>
#include<algorithm>
using namespace std;

int n, d, ans, a[1005];

int abss(const int i) {return i > 0 ? i : -i;}

int main() {
  scanf("%d %d", &n, &d);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (abss(a[i] - a[j]) <= d) ans += 2;
    }
  }
  printf("%d\n", ans); 
  return 0;
}