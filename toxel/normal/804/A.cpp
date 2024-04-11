#include<bits/stdc++.h>

int n;

int main(){
	scanf("%d", &n);
	return printf("%d\n", n & 1 ? n >> 1 : (n >> 1) - 1), 0;
}