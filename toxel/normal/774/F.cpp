#include<bits/stdc++.h>

const int N = 50010;
const int M = 7;

int a[N];
int n;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	if (!(n % M)){
		int min = INT_MAX, sit;
		for (int i = 1; i <= n; ++ i){
			if (!(i % M)){
				continue;
			}
			if (min > a[i]){
				min = a[i];
				sit = i;
			}
		}
		return printf("%d\n", sit), 0;
	}
	int min = INT_MAX;
	for (int i = 1; i <= n; ++ i){
		min = std::min(min, a[i]);
	}
	int x = (min - 1) / (M - 1) * (M - 1);
	for (int i = 1; i <= n; ++ i){
		a[i] -= x;
	}
	for (int i = 1, j = 1; ; i = i % n + 1, j = j % M + 1){
		if (j == M){
			continue;
		}
		-- a[i];
		if (!a[i]){
			return printf("%d\n", i), 0;
		}
	}
}