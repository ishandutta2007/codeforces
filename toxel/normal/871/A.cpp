#include<bits/stdc++.h>

int main(){
	int query;
	scanf("%d", &query);
	while (query --){
		int n;
		scanf("%d", &n);
		if (n % 4 == 0){
			printf("%d\n", n >> 2);
		}
		else if (n % 4 == 1){
			printf("%d\n", n < 9 ? -1 : n - 4 >> 2);
		}
		else if (n % 4 == 2){
			printf("%d\n", n < 6 ? -1 : n >> 2);
		}
		else if (n % 4 == 3){
			printf("%d\n", n < 15 ? -1 : n - 4 >> 2);
		}
	}
	return 0;
}