#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair <ll, ll> pii;

std::map <ll, std::vector <pii>> Hash;

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		ll w, h, c;
		scanf("%I64d%I64d%I64d", &w, &h, &c);
		Hash[w].push_back({h, c});
	}
	for (auto &u : Hash){
		std::sort(u.second.begin(), u.second.end());
	}
	for (auto &u : Hash){
		if (u.second.size() != Hash.begin() -> second.size()){
			puts("0");
			return 0;
		}
	}
	for (int i = 0, sz = Hash.begin() -> second.size(); i < sz; ++ i){
		for (auto &u : Hash){
			if (u.second[i].first != Hash.begin() -> second[i].first){
				puts("0");
				return 0;
			}
			ll x0 = u.second[i].second, y0 = u.second[0].second;
			ll x1 = Hash.begin() -> second[i].second, y1 = Hash.begin() -> second[0].second;
			ll gcd0 = std::__gcd(x0, y0), gcd1 = std::__gcd(x1, y1);
			x0 /= gcd0, y0 /= gcd0;
			x1 /= gcd1, y1 /= gcd1;
			if (x0 != x1 || y0 != y1){
				puts("0");
				return 0;
			}
		}
	}
	ll lcm0 = 1;
	ll value = Hash.begin() -> second[0].second;
	for (auto &u : Hash.begin() -> second){
		ll x = value / std::__gcd(value, u.second);
		lcm0 = x / std::__gcd(x, lcm0) * lcm0;
	}
	ll lcm1 = 1;
	for (auto &u : Hash){
		ll x = value / std::__gcd(value, u.second[0].second);
		lcm1 = x / std::__gcd(x, lcm1) * lcm1;
	}
	int ans = 0;
	std::set <ll> fact;
	for (ll x = 1; x * x <= value; ++ x){
		if (value % x == 0){
			fact.insert(x);
			fact.insert(value / x);
		}
	}
	for (auto u : fact){
		ans += u % lcm0 == 0 && value / u % lcm1 == 0;
	}
	printf("%d\n", ans);
	return 0;
}