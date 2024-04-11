#include <cstdio>

int n;

int ask(int c) 
{
	printf("+ %d\n", c);
	fflush(stdout);
	int re;
	scanf("%d", &re);
	return re;
}

int main() 
{
	scanf("%d", &n);
	int l = 1, r = n - 1;
	while (l < r) {
		int m = l + r >> 1;
		++m;
		if (!(m % n)) --m;
		int nn = m / n * n + n;
		if (ask(nn - m) == nn / n) l = m;
		else r = m - 1;
		l += nn - m;
		r += nn - m;
	}
	printf("! %d\n", l);
	return 0;
}