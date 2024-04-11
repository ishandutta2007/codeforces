#include<bits/stdc++.h>

int n, k;

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++ i){
		putchar('a' + i % k);
	}
	return printf("\n"), 0;
}