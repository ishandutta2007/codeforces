#include <cstdio>

typedef unsigned long long ull;

ull get_count(int n2) {
	ull n = n2;
	ull tot = n;
	for(ull i = 10ull; (i - 1ull) < n; i *= 10ull)
		tot += n - (i - 1);
	return tot;	
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%I64u\n", get_count(n));
}