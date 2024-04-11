#include<bits/stdc++.h>

int n, m;

int main(){
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		sum += x;
	}
	scanf("%d", &m);
	for (int i = 0, l, r; i < m; ++ i){
		scanf("%d%d", &l, &r);
		if (sum > r){
			continue;
		}
		return printf("%d\n", std::max(sum, l)), 0;
	}
	return printf("-1\n"), 0;
}