#include<bits/stdc++.h>

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	return printf("%d %d\n", k == n || !k ? 0 : 1, !k ? 0 : k <= n / 3 ? k << 1 : n - k), 0;
}