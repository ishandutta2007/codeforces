#include<bits/stdc++.h>

int a, b;

int main(){
	scanf("%d%d", &a, &b);
	int cnt = 0;
	while (a <= b){
		a *= 3;
		b <<= 1;
		++ cnt;
	}
	return printf("%d\n", cnt), 0;
}