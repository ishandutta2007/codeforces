#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	long long a, b, c, d, e;
	scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e);

	printf("%lld", max(min(b, d) - max(a, c) + 1 - (a <= e&&e <= b&&c <= e&&e <= d), 0ll));
}