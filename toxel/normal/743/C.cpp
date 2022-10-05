#include<bits/stdc++.h>

int n;

int main(){
	scanf("%d", &n);
	if (n == 1)
		return printf("-1\n"), 0;
	printf("%d %d %d\n", n, n + 1, n * (n + 1));
	return 0;
}