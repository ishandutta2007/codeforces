#include<stdio.h>
long double pd[10001][1001];
int ans[1001];
int main(){
	int n, q, p, x=1;
	scanf("%d%d", &n, &q);
	pd[0][0] = 1;
	for(int d=1; x<=1000; d++){
		for(int i=1; i<=n; i++){
			pd[d][i] = pd[d-1][i]*i/n + pd[d-1][i-1]*(n-i+1)/n;
		}
		while(pd[d][n]*2000>=x-1e-7 && x <= 1000){
			ans[x] = d;
			x++;
		}
	}
	for(int i=1; i<=q; i++){
		scanf("%d", &p);
		printf("%d\n", ans[p]);
	}
	return 0;
}