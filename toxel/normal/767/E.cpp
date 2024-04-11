#include<bits/stdc++.h>

const int N = 100010;

std::set <std::pair <int, int>> set;
int n, m, c[N], w[N], ans[N][2];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &w[i]);
	}
	long long ret = 0;
	for (int i = 0; i < n; ++ i){
		if (c[i] % 100){
			ans[i][0] = c[i] / 100;
			ans[i][1] = c[i] % 100;
			set.insert({(100 - ans[i][1]) * w[i], i});
			m -= ans[i][1];
		}
		else{
			ans[i][0] = c[i] / 100;
		}
		if (m < 0){
			m += 100;
			auto u = set.begin();
			ret += u -> first;
			++ ans[u -> second][0];
			ans[u -> second][1] = 0;
			set.erase(u);
		}
	}
	printf("%I64d\n", ret);
	for (int i = 0; i < n; ++ i){
		printf("%d %d\n", ans[i][0], ans[i][1]);
	}
	return 0;
}