#include <cstdio>
using namespace std;

const int LG = 60;
long long a[LG];

void testcase() 
{
	long long n;
	scanf("%lld", &n);
	++n;
	int k = (long long)59;
	long long res = 0;
	bool was = false;
	long long last;
	while (k >= 0) {
		if ((n >> k) & 1) {
			res += a[k];
			res += k + 1;
			last = k + 1;
		}
		--k;
	}
	printf("%lld\n", res - last);
}

int main() 
{
	a[0] = 0;
	for (int i = 1; i < LG; ++i) {
		a[i] = a[i - 1] * 2 + i;
	}
	int t;
	scanf("%d", &t);
	while (t--) testcase();
	return 0;
}