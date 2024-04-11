#include<bits/stdc++.h>
#define ll long long

std::set <ll> set;
ll n, k;

int main(){
	scanf("%I64d%I64d", &n, &k);
	for (ll i = 1; i * i <= n; ++ i){
		if (n % i == 0){
			set.insert(i);
			set.insert(n / i);
		}
	}
	if (set.size() < k){
		return printf("-1\n"), 0;
	}
	int cnt = 1;
	for (auto u = set.begin(); u != set.end(); ++ u, ++ cnt){
		if (cnt == k){
			return printf("%I64d\n", *u), 0;
		}
	}
	return 0;
}