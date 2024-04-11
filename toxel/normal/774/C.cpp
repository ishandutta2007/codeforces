#include<bits/stdc++.h>

int n;

int main(){
	scanf("%d", &n);
	if (n & 1){
		printf("7");
		n -= 3;
	}
	for (int i = 0; i < n >> 1; ++ i){
		putchar('1');
	}
	return printf("\n"), 0;
}