#include<cstdio>
#include<algorithm>
using namespace std;

const long long MOD = 1000000007;

int s[] = {1, 2, 4, 6, 12, 16, 18, 30, 60, 88, 106, 126, 520, 606, 1278, 2202, 2280, 3216, 4252, 4422, 9688, 9940, 11212, 19936, 21700, 23208, 44496, 86242, 110502, 132048, 216090, 756838, 859432, 1257786, 1398268, 2976220, 3021376, 6972592, 13466916, 20996010};

long long go(const int i) {
  if (i == 1) return 2;
  long long t1 = go(i >> 1);
  t1 *= t1;
  t1 %= MOD;
  if (i % 2) t1 *= 2;
  t1 %= MOD;
  return t1;
}

int main() {
  int n;
  scanf("%d", &n);
  long long ans = go(s[n - 1]) - 1;
  if (ans < 0) ans += MOD;
  printf("%I64d\n", ans);
  return 0;
}