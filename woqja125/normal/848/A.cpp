#include<stdio.h>
void solve(int n, char x='a') {
	printf("%c", x);
	for (int i = 1, s = 0; n-i>=0; n-=(i++)) {
		printf("%c", x);
	}
	if (n > 0) solve(n, x + 1);
}
int main() {
	int n;
	scanf("%d", &n);
	solve(n);
	return 0;
}