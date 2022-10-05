#include<bits/stdc++.h>

const int N = 200010;

int a[N];

int main(){
	int h;
	scanf("%d", &h);
	for (int i = 0; i <= h; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < h; ++ i){
		if (a[i] > 1 && a[i + 1] > 1){
			puts("ambiguous");
			int fa = 0;
			for (int j = 0; j <= h; ++ j){
				for (int k = 0; k < a[j]; ++ k){
					printf("%d ", fa);
				}
				fa += a[j];
			}
			putchar('\n');
			fa = 0;
			for (int j = 0; j <= h; ++ j){
				for (int k = 0; k < a[j]; ++ k){
					printf("%d ", j == i + 1 && k == 0 ? fa - 1 : fa);
				}
				fa += a[j];
			}
			putchar('\n');
			return 0;
		}
	}
	puts("perfect");
	return 0;
}