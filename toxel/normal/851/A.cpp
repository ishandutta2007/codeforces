#include<bits/stdc++.h>

int n, k, t;

int main(){
	scanf("%d%d%d", &n, &k, &t);
	return printf("%d\n", std::min(k, std::min(n + k - t, t))), 0;
}