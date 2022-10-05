#include<bits/stdc++.h>

const int N = 200010;

int n, m;

int main(){
	scanf("%d", &n);
	int min = INT_MAX, max = 0;
	for (int i = 0, x, y; i < n; ++ i){
		scanf("%d%d", &x, &y);
		min = std::min(min, y);
		max = std::max(max, x);
	}
	int ans = 0;
	scanf("%d", &m);
	for (int i = 0, x, y; i < m; ++ i){
		scanf("%d%d", &x, &y);
		ans = std::max(ans, x - min);
		ans = std::max(ans, max - y);
	}
	return printf("%d\n", ans), 0;
}