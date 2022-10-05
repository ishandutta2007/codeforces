#include<bits/stdc++.h>

int n;

int main(){
	scanf("%d", &n);
	int m = n;
	int cnt = 0;
	while (n >= 10){
		++ cnt;
		n /= 10;
	}
	++ n;
	for (int i = 0; i < cnt; ++ i){
		n *= 10;
	}
	return printf("%d\n", n - m), 0;
}