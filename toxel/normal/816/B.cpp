#include<bits/stdc++.h>

const int N = 200010;

int pre[N], preans[N];
int n, k, test;

int main(){
	scanf("%d%d%d", &n, &k, &test);
	for (int i = 0, l, r; i < n; ++ i){
		scanf("%d%d", &l, &r);
		++ r;
		++ pre[l];
		-- pre[r];
	}
	for (int i = 1; i < N; ++ i){
		pre[i] += pre[i - 1];
		if (pre[i] >= k){
			++ preans[i];
		}
	}
	for (int i = 1; i < N; ++ i){
		preans[i] += preans[i - 1];
	}
	while (test --){
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", preans[r] - preans[l - 1]);
	}
	return 0;
}