#include<bits/stdc++.h>

int a[][3] = {{0, 1, 2}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}, {0, 2, 1}};

int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	return printf("%d", a[n % 6][x]), 0;
}