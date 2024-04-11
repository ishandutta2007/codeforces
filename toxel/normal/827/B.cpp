#include<bits/stdc++.h>

int n, k;

int main(){
	scanf("%d%d", &n, &k);
	int x = (n - 1) / k, y = (n - 1) % k;
	printf("%d\n", y ? y > 1 ? x + 1 << 1 : (x << 1) + 1 : x << 1);
	for (int i = 2; i <= k + 1; ++ i){
		printf("1 %d\n", i);
	}
	for (int i = 2; i <= n - k; ++ i){
		printf("%d %d\n", i, i + k);
	}
	return 0;
}