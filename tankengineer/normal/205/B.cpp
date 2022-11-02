#include<cstdio>
#include<algorithm>
using namespace std;

int n, t1, t2;
long long ans;

int main() {
  scanf("%d %d", &n, &t1);
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &t2);
    ans += max(0, t1 - t2);
    t1 = t2;
  }
  printf("%I64d\n", ans);
  return 0;
}