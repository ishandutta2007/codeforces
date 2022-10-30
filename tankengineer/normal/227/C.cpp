#include<cstdio>
#include<algorithm>
using namespace std;

long long n, m;

long long go(const long long &n) {
  if (n == 0) return 1 % m;
  if (n == 1) return 3 % m;
  long long ret = go(n / 2);
  ret = ret * ret % m;
  if (n % 2) ret = ret * 3 % m;
  return ret;
}

int main() {
  scanf("%I64d %I64d", &n, &m);
  long long ans = (go(n) - 1 + m) % m;
  printf("%I64d\n", ans);
  return 0;
}