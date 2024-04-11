#include <cstdio>
#include <algorithm>

int query(bool type, int i, int j) 
{
	if (type) printf("and ");
	else printf("or ");
	printf("%d %d\n", i + 1, j + 1);
	fflush(stdout);
	int re;
	scanf("%d", &re);
	return re;
}

const int N = 10000;
int n, k, Or[N], And[N], Xor[N], a[N];

int main() 
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; ++i) {
		Or[i] = query(0, i - 1, i);
		And[i] = query(1, i - 1, i);
		Xor[i] = Or[i] - And[i];
	}
	a[0] = Or[1] + And[1] - (Or[2] + And[2]) + query(0, 0, 2) + query(1, 0, 2) >> 1;
	for (int i = 1; i < n; ++i) a[i] = a[i - 1] ^ Xor[i];
	std::sort(a, a + n);
	printf("finish %d\n", a[k - 1]);
	return 0;
}