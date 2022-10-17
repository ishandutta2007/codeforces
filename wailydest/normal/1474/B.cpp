#include <cstdio>

bool pp(int n) 
{
	for (int i = 2; i * i <= n; ++i) if (!(n % i)) return false;
	return true;
}

const int N = 1000000;
int t, n;
bool p[N];

int main() 
{
	for (int i = 2; i < N; ++i) p[i] = pp(i);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int i, j;
		for (i = 1 + n; !p[i]; ++i);
		for (j = i + n; !p[j]; ++j);
		printf("%lld\n", (long long)j * i);
	}
	return 0;
}