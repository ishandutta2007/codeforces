//27A
#include<cstdio>
#include<algorithm>

using namespace std;

int n, t1, cnt[3005];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t1); cnt[t1]++;
  }
  t1 = 1;
  while (cnt[t1]) t1++;
  printf("%d\n", t1);
  return 0;
}