#include<bits/stdc++.h>
#define ll long long

const ll MAX = 1e15;

std::set <ll> set;
std::map <ll, int> Hash;
ll n, k;

int main(){
	scanf("%I64d%I64d", &n, &k);
	if (k == 1){
		set = {1};
	}
	else if (k == -1){
		set = {1, -1};
	}
	else{
		ll x = 1;
		while (std::abs(x) < MAX){
			set.insert(x);
			x *= k;
		}
	}
	ll ans = 0, now = 0;
	++ Hash[0];
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		now += x;
		for (auto u = set.begin(); u != set.end(); ++ u){
			ans += Hash[now - *u];
		}
		++ Hash[now];
	}
	return printf("%I64d\n", ans), 0;
}