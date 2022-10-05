#include<bits/stdc++.h>

const int N = 100010;

int main(){
	int n, m, h;
	scanf("%d%d%d", &n, &m, &h);
	int sum = 0, num = 0;
	for (int i = 0, x; i < m; ++ i){
		scanf("%d", &x);
		sum += x;
		if (h == i + 1){
			num = x;
		}
	}
	if (n > sum){
		return printf("-1"), 0;
	}
	if (sum - num < n - 1){
		return printf("1\n"), 0;
	}
	double ans = 0;
	for (int i = 1; i <= sum - num; ++ i){
		ans += std::log(i);
	}
	for (int i = 1; i <= sum - n; ++ i){
		ans += std::log(i);
	}
	for (int i = 1; i <= sum - 1; ++ i){
		ans -= std::log(i);
	}
	for (int i = 1; i <= sum - num - n + 1; ++ i){
		ans -= std::log(i);
	}
	printf("%.10lf\n", 1 - std::exp(ans));
	return 0;
}