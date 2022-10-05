#include<bits/stdc++.h>

const int N = 100010;

int min[N], n, ans[N];
std::vector <int> prime;

int main(){
	for (int i = 2; i < N; ++ i){
		if (!min[i]){
			min[i] = i;
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() && prime[j] <= i; ++ j){
			if (prime[j] * i >= N){
				break;
			}
			min[prime[j] * i] = prime[j];
		}
	}
	scanf("%d", &n);
	printf(n >= 3 ? "2\n" : "1\n");
	for (int i = 2; i <= n + 1; ++ i){
		printf(min[i] == i ? "1 " : "2 ");
	}
	putchar('\n');
	return 0;
}