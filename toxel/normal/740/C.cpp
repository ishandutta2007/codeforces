#include<bits/stdc++.h>
const int N = 100010;

int n, m;

int main(){
	scanf("%d%d", &n, &m);
	int min = INT_MAX;
	for (int i = 0, l, r; i < m; ++ i){
		scanf("%d%d", &l, &r);
		min = std::min(min, r - l + 1);
	}
	printf("%d\n", min);
	for (int i = 0; i < n; ++ i)
		printf("%d ", i % min);
	printf("\n");
	return 0;
}