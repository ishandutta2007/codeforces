#include<bits/stdc++.h>

int n, h, d;

int main(){
	scanf("%d%d%d", &n, &d, &h);
	if (n - 1 < d){
		puts("-1");
		return 0;
	}
	if (h > d || h * 2 < d){
		puts("-1");
		return 0;
	}
	if (h == 1){
		if (n == 2){
			puts("1 2");
			return 0;
		}
		if (d == 1){
			puts("-1");
			return 0;
		}
		for (int i = 2; i <= n; ++ i){
			printf("1 %d\n", i);
		}
		return 0;
	}
	if (h == d){
		for (int i = 1; i <= d - 1; ++ i){
			printf("%d %d\n", i, i + 1);
		}
		for (int i = d + 1; i <= n; ++ i){
			printf("%d %d\n", d, i);
		}
		return 0;
	}
	for (int i = 1; i <= h; ++ i){
		printf("%d %d\n", i, i + 1);
	}
	printf("1 %d\n", h + 2);
	for (int i = h + 2; i <= d; ++ i){
		printf("%d %d\n", i, i + 1);
	}
	for (int i = d + 2; i <= n; ++ i){
		printf("1 %d\n", i);
	}
	return 0;
}