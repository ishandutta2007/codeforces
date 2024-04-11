#include<bits/stdc++.h>

const int N = 210;

int n, k, a[N], kid[N];

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++ i){
		scanf("%d", &a[i]);
	}
	int lead = 0;
	for (int i = 0; i < n; ++ i){
		kid[i] = i + 1;
	}
	for (int j = 0; j < k; ++ j, -- n){
		int sit = (lead + a[j]) % n;
		printf("%d ", kid[sit]);
		for (int i = sit; i < n - 1; ++ i){
			kid[i] = kid[i + 1];
		}
		lead = sit;
	}
	return 0;
}