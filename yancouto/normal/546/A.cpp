#include <cstdio>

int main() {
	int k, n, w;
	scanf("%d %d %d", &k, &n, &w);
	long long l = w;
	long long nn = n;
	long long a = k * ((l + 1) * l) / 2;
	if(nn > a) puts("0");
	else {
		printf("%I64d\n", a - nn);
	}
	return 0;
}