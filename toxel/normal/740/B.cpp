#include<bits/stdc++.h>
const int N = 110;

int pre[N], n, m;

int main(){
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (int i = 1, x; i <= n; ++ i){
		scanf("%d", &x);
		pre[i] = pre[i - 1] + x;
	}
	for (int i = 0, l, r; i < m; ++ i){
		scanf("%d%d", &l, &r);
		if (pre[r] - pre[l - 1] > 0)
			ans += pre[r] - pre[l - 1];
	}
	printf("%d\n", ans);
	return 0;
}