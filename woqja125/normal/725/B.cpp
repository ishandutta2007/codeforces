#include<stdio.h>
int t[6] = { 3, 4, 5, 2, 1, 0 };
int main() {
	int m;
	long long n;
	char c;
	scanf("%lld%c", &n, &c);
	m = c - 'a'; n--;
	long long ans = n / 4 * 16;
	n %= 2; ans += n * 7;
	ans += t[m];
	printf("%lld", ans+1);
	return 0;
}