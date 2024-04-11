#include<bits/stdc++.h>

const int N = 100010;

int a[N], b[N];
int n;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n - 1; ++ i){
		a[i] = b[i] + b[i + 1];
	}
	a[n - 1] = b[n - 1];
	for (int i = 0; i < n; ++ i){
		printf("%d ", a[i]);
	}
	return printf("\n"), 0;
}