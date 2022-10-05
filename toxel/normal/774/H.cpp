#include<bits/stdc++.h>

const int N = 2010;

int c[N];
int n;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &c[i]);
	}
	for (int i = 1; i < n; ++ i){
		c[i] -= c[i + 1];
	}
	for (int i = 1; i < n; ++ i){
		c[i] -= c[i + 1];
	}
	for (int i = 1, x = 0; i <= n; ++ i){
		for (int j = 0; j < c[i]; ++ j){
			for (int k = 0; k < i; ++ k){
				putchar('a' + x);
			}
			x = (x + 1) % 26;
		}
	}
	return printf("\n"), 0;
}