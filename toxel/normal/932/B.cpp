#include<bits/stdc++.h>

const int N = 1000010;
const int M = 10;

int a[N], pre[N][M];

int calc(int n){
	int ret = 1;
	for ( ; n; n /= 10){
		int x = n % 10;
		if (x){
			ret *= x;
		}
	}
	return ret;
}

int main(){
	for (int i = 1; i <= 9; ++ i){
		a[i] = i;
	}
	for (int i = 10; i < N; ++ i){
		a[i] = a[calc(i)];
	}
	for (int i = 1; i < N; ++ i){
		for (int j = 0; j < M; ++ j){
			pre[i][j] = pre[i - 1][j];
			if (j == a[i]){
				++ pre[i][j];
			}
		}
	}
	int q;
	scanf("%d", &q);
	while (q --){
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", pre[r][k] - pre[l - 1][k]);
	}
	return 0;
}