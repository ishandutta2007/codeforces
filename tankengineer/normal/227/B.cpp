#include<cstdio>
#include<algorithm>
using namespace std;

int p[100005], n, m, t1;
long long ans1, ans2;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t1);
    p[t1] = i;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &t1);
    ans1 += p[t1];
    ans2 += n - p[t1] + 1;
  }
  printf("%I64d %I64d\n", ans1, ans2);
  return 0;
}