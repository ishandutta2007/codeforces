#include<bits/stdc++.h>

const int N = 110;

int a[N], b[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n << 1; ++ i){
		scanf("%d", &a[i]);
	}
	int ans = INT_MAX;
	for (int i = 0; i < n << 1; ++ i){
		for (int j = i + 1; j < n << 1; ++ j){
			int cnt = 0;
			for (int k = 0; k < n << 1; ++ k){
				if (k != i && k != j){
					b[cnt ++] = a[k];
				}
			}
			std::sort(b, b + cnt);
			int sum = 0;
			for (int k = 0; k < cnt; k += 2){
				sum += b[k + 1] - b[k];
			}
			ans = std::min(ans, sum);
		}
	}
	return printf("%d\n", ans), 0;
}