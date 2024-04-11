#include<bits/stdc++.h>

const int N = 200010;

int n, k, t, a[N];

int main(){
	scanf("%d%d%d", &n, &t, &k);
	int min = 0;
	for (int i = 1; i <= t; ++ i){
		scanf("%d", &a[i]);
		if (a[i] < a[i - 1]){
			min += a[i - 1] - a[i];
		}
	}
	min += a[t];
	if (k < min || k > n - t){
		return printf("-1\n"), 0;
	}
	printf("%d\n", n);
	for (int i = 1; i <= a[1]; ++ i){
		printf("1 %d\n", 1 + i);
	}
	int pre = 2;
	k -= min;
	for (int i = 1; i < t; ++ i){
		int x = std::min(a[i], a[i + 1]);
		x = std::min(x - 1, k);
		k -= x;
		if (a[i] > a[i + 1]){
			x += a[i] - a[i + 1];
		}
		for (int j = 0; j < a[i] - x; ++ j){
			printf("%d %d\n", pre + j, pre + j + a[i]);
		}
		for (int j = 0; j < a[i + 1] - a[i] + x; ++ j){
			printf("%d %d\n", pre, pre + 2 * a[i] - x + j);
		}
		pre += a[i];
	}
	return 0;
}