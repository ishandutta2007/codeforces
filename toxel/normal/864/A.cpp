#include<bits/stdc++.h>

const int N = 110;

int n;
int cnt[N];

int main(){
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		++ cnt[x];
	}
	for (int i = 0; i < N; ++ i){
		if (cnt[i] && cnt[i] != n >> 1){
			return printf("NO\n"), 0;
		}
	}
	printf("YES\n");
	for (int i = 0; i < N; ++ i){
		if (cnt[i]){
			printf("%d ", i);
		}
	}
	return printf("\n"), 0;
}