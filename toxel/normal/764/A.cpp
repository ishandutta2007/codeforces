#include<bits/stdc++.h>

int n, m, z;

int main(){
	scanf("%d%d%d", &n, &m, &z);
	return printf("%d\n", z / (n * m / std::__gcd(n, m))), 0;
	
}