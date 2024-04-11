#include<bits/stdc++.h>

const int N = 100010;

std::vector <int> prime;
int min[N], max[N];

int main(){
	for (int i = 2; i < N; ++ i){
		if (!min[i]){
			min[i] = i;
			prime.push_back(i);
		}
		for (int j = 0, k, sz = prime.size(); j < sz && i * prime[j] < N; ++ j){
			min[k = i * prime[j]] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
	int n;
	scanf("%d", &n);
	if (n == 1){
		printf("1\n");
		return 0;
	}
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		std::vector <int> fact;
		while (x > 1){
			int y = min[x];
			fact.push_back(y);
			while (x % y == 0){
				x /= y;
			}
		}
		int mmax = 0;
		for (auto u : fact){
			mmax = std::max(max[u], mmax);
		}
		for (auto u : fact){
			max[u] = mmax + 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++ i){
		ans = std::max(ans, max[i]);
	}
	return printf("%d\n", ans), 0;
}