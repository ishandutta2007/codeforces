#include<bits/stdc++.h>

int k2, k3, k5, k6;

int main(){
	scanf("%d%d%d%d", &k2, &k3, &k5, &k6);
	int x = std::min(std::min(k2, k5), k6);
	int ans = 256 * x;
	k2 -= x;
	x = std::min(k2, k3);
	ans += 32 * x;
	return printf("%d\n", ans), 0;
}