#include<bits/stdc++.h>

const int N = 100010;

int a[N];

int main(){
	int n, u;
	scanf("%d%d", &n, &u);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	double max = -1;
	for (int i = 0, j = 0; i < n - 2; ++ i){
		j = std::max(j, i + 2);
		while (j < n && a[j] - a[i] <= u){
			++ j;
		}
		if (j == i + 2){
			continue;
		}
		-- j;
		max = std::max(max, 1 - 1.0 * (a[i + 1] - a[i]) / (a[j] - a[i]));
	}
	if (max < 0){
		puts("-1");
		return 0;
	}
	printf("%.10lf\n", max);
	return 0;
}