#include<bits/stdc++.h>

int n, m, k;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	int min = INT_MAX;
	for (int i = 1, x; i <= n; ++ i){
		scanf("%d", &x);
		if (x && x <= k){
			min = std::min(min, std::abs(m - i));
		}
	}
	return printf("%d\n", min * 10), 0;
}