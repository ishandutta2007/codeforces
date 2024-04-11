#include<bits/stdc++.h>

int a[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};
int n;

int main(){
	scanf("%d", &n);
	if (!n){
		return printf("1\n"), 0;
	}
	int cnt = 0;
	while (n){
		cnt += a[n % 16];
		n /= 16;
	}
	return printf("%d\n", cnt), 0;
}