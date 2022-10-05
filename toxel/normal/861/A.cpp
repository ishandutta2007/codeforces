#include<bits/stdc++.h>

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	if (!k) return printf("%d\n", n), 0;
	int cnt = 0;
	while (n % 10 == 0){
		n /= 10;
		++ cnt;
		if (cnt >= k) break;
	}
	k -= cnt;
	for (int i = 0; i < k; ++ i){
		if (n % 5 == 0){
			n /= 5;
		}
		else if (n % 2 == 0){
			n /= 2;
		}
	}
	printf("%d", n);
	for (int i = 0; i < k + cnt; ++ i){
		putchar('0');
	}
	return printf("\n"), 0;
}