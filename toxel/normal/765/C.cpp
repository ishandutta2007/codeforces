#include<bits/stdc++.h>

int k, a, b;

int main(){
	scanf("%d%d%d", &k, &a, &b);
	int ans = a / k + b / k;
	if (a % k && !(b / k) || b % k && !(a / k)){
		ans = -1;
	}
	return printf("%d\n", ans), 0;
}