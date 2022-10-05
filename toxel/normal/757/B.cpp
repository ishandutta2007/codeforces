#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

int min[N], cnt[N];
std::vector <int> prime;
std::map <int, int> fact;

void get_fact(int &n){
	for (ll i = 0; i < prime.size(); ++ i){
		ll x = prime[i];
		if (x * x > n)
			break;
		if (!(n % x)){
			++ fact[x];
			n /= x;
			return;
		}
	}
	++ fact[n];
	n = 1;
}

int main(){
	for (int i = 2; i < N; ++ i){
		if (!min[i]){
			min[i] = i;
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() && prime[j] <= i; ++ j){
			if (prime[j] * i >= N)
				break;
			min[prime[j] * i] = prime[j];
		}
	}
	int n;
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		fact.clear();
		while (x > 1){
			get_fact(x);
		}
		for (auto u = fact.begin(); u != fact.end(); ++ u){
			++ cnt[u -> first];
		}
	}
	int max = 1;
	for (int i = 0; i < N; ++ i){
		max = std::max(max, cnt[i]);
	}
	printf("%d\n", max);
	return 0;
}