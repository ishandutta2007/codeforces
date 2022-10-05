#include<bits/stdc++.h>

int n;

int main(){
	scanf("%d", &n);
	int left = -INT_MAX, right = INT_MAX, now = 0;
	for (int i = 0, x, div; i < n; ++ i){
		scanf("%d%d", &x, &div);
		div == 1 ? left = std::max(left, 1900 - now) : right = std::min(right, 1899 - now);
		now += x;
	}
	if (left > right)
		return printf("Impossible\n"), 0;
	if (right == INT_MAX)
		return printf("Infinity\n"), 0;
	return printf("%d\n", right + now), 0;
}