#include<bits/stdc++.h>

int main(){
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i * a <= n; ++ i){
		int x = n - i * a;
		if (x % b) continue;
		int j = x / b;
		int pre = 1;
		for (int k = 0; k < i; ++ k){
			int now = pre + a - 1;
			for (int u = pre + 1; u <= now; ++ u){
				printf("%d ", u);
			}
			printf("%d ", pre);
			pre = now + 1;
		}
		for (int k = 0; k < j; ++ k){
			int now = pre + b - 1;
			for (int u = pre + 1; u <= now; ++ u){
				printf("%d ", u);
			}
			printf("%d ", pre);
			pre = now + 1;
		}
		putchar('\n');
		return 0;
	}
	printf("-1\n");
	return 0;
}