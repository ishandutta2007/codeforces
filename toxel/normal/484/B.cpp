#include<bits/stdc++.h>

const int N = 1000010;

int cnt[N], min[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		++ cnt[x];
	}
	for (int i = 1; i < N; ++ i){
		min[i] = cnt[i] ? i : min[i - 1];
	}
	int max = 0;
	for (int i = 1; i < N; ++ i){
		if (cnt[i]){
			for (int j = 2 * i; j < N; j += i){
				max = std::max(max, min[j - 1] % i);
			}
			max = std::max(max, min[N - 1] % i);
		}
	}
	return printf("%d\n", max), 0;
}