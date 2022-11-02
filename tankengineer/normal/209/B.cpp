#include<cstdio>
#include<algorithm>
using namespace std;

long long a, b, c;

long long getans(long long a, long long b, long long c) {
  if ((a - b) % 2) return a + b + c;
	long long x, y, z = max(0ll, (a - b) / 2);
  y = (2 * z + b - a) / 2;
  x = a - z + y;
  return a + b + c - max(0ll, (c - y - z + x));
}

int main() {
	scanf("%I64d %I64d %I64d", &a, &b, &c);
	long long t1 = getans(a, b, c), t2 = getans(b, c, a), t3 = getans(c, a, b);
	long long ans = min(min(t1, t2), t3);
	if (ans == a + b + c) ans = -1;
	printf("%I64d\n", ans);
	return 0;
}