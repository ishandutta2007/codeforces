#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, t1, cntn[11], cnt[11], ans;

void cal(const int i) {
  memset(cnt, 0, sizeof(cnt));
  t1 = i;
  while (t1) {
    cnt[t1 % 10]++;
    t1 /= 10;
  }
  for (int j = 0; j < 10; ++j) {
    if (min(cnt[j], cntn[j]) > 0) {
      ++ans;
      return;
    }
  }
}

int main() {
  scanf("%d", &n);
  t1 = n;
  while (t1) {
    cntn[t1 % 10]++;
    t1 /= 10;
  }
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      cal(i);
      if (n / i != i) cal(n / i);
    }
  }
  printf("%d\n", ans);
  return 0;
}