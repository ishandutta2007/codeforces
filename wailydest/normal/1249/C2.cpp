#include <cstdio>
using namespace std;

const int N = 39;

long long po[N];

long long get(long long n) 
{
	int i;
	for (i = 0; i < N && po[i] < n; ++i);
	if ((po[i] - 1) / 2 < n) return po[i];
	return po[i - 1] + get(n - po[i - 1]);
}

int main() 
{
	po[0] = 1;
	for (int i = 1; i < N; ++i) po[i] = 3 * po[i - 1];
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", get(n));
	}
	return 0;
}