#include<stdio.h>
char s[1000010];
int main() {
	int n;
	scanf("%s", s);
	for (n = 0; s[n]; n++);
	const int MOD = 1000000007;
	int re = 0;
	int c = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'b') c++;
		if (s[i] == 'a') {
			re = (re + c) % MOD;
			c = c * 2ll % MOD;
		}
	}
	printf("%d\n", re);
	//ile (1);
	return 0;
}