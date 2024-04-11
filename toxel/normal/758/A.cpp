#include<bits/stdc++.h>

const int N = 110;

int n, a[N];

int main(){
	scanf("%d", &n);
	int max = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		max = std::max(a[i], max);
	}
	int ans = 0;
	for (int i = 0; i < n; ++ i){
		ans += max - a[i];
	}
	printf("%d\n", ans);
	return 0;
}