#include<bits/stdc++.h>

int x1, x2, x3, x4;

int main(){
	scanf("%d%d%d%d", &x1, &x2, &x3, &x4);
	int a1 = x1 ^ x2, a2 = x3 | x4, a3 = x2 & x3, a4 = x1 ^ x4;
	int b1 = a1 & a2, b2 = a3 | a4;
	return printf("%d\n", b1 ^ b2), 0;
}