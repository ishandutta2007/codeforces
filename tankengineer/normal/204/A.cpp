#include<cstdio>
#include<algorithm>
using namespace std;

long long go(const long long n) {
  unsigned long long ret = 0, tmp = 10;
  if (n < 10) return n; else ret += 9;

  while (tmp * 10 <= n) {
	  tmp *= 10;
	  ret += 9 * tmp / 100;
	}
	int t1 = (int)(n / tmp), t2 = (int)(n % 10);
	unsigned long long mid = (n % tmp) / 10;
	for (int i = 1; i < t1; ++i) ret += tmp / 10;
	ret += mid + ((t1 <= t2) ? 1 : 0);
	return ret;
}

int main() {
	long long l, r;
	scanf("%I64d %I64d", &l, &r);
	printf("%I64d\n", go(r) - go(l - 1));
	return 0;
}