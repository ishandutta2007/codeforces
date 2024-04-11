#include<bits/stdc++.h>

const int N = 1000010;

int min[N];
std::vector <int> prime;

int low(int n){
	int nn = n;
	int max = 0;
	while (n != 1){
		max = std::max(max, min[n]);
		n /= min[n];
	}
	return nn - max + 1;
}

int main(){
	for (int i = 2; i < N; ++ i){
		if (!min[i]){
			min[i] = i;
			prime.push_back(i);
		}
		for (int j = 0, sz = prime.size(), k; j < sz && prime[j] * i < N; ++ j){
			min[k = prime[j] * i] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
	int x;
	scanf("%d", &x);
	int y = low(x);
	int ans = INT_MAX;
	for (int i = y; i <= x; ++ i){
		if (min[i] != i){
			ans = std::min(ans, low(i));
		}
	}
	printf("%d\n", ans);
	return 0;
}