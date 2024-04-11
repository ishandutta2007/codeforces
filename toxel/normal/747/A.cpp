#include<bits/stdc++.h>

int main(){
	int n;
	scanf("%d", &n);
	int ans;
	for (int i = 1; i <= n; ++ i){
		if (!(n % i) && i <= n / i)
			ans = i;
	}
	printf("%d %d\n", ans, n / ans);
	return 0;
}