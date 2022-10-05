#include<bits/stdc++.h>
#define ll long long

ll x, y, l, r;
std::vector <ll> vec1, vec2, vec;

int main(){
	scanf("%I64d%I64d%I64d%I64d", &x, &y, &l, &r);
	for (ll now = 1; ; now *= x){
		vec1.push_back(now);
		if (1.0 * now * x >= 2e18){
			break;
		}
	}
	for (ll now = 1; ; now *= y){
		vec2.push_back(now);
		if (1.0 * now * y >= 2e18){
			break;
		}
	}
	for (auto u : vec1){
		for (auto v : vec2){
			if (u + v >= l && u + v <= r){
				vec.push_back(u + v);
			}
		}
	}
	vec.push_back(l - 1);
	vec.push_back(r + 1);
	std::sort(vec.begin(), vec.end());
	ll ans = 0;
	for (int i = 0, sz = vec.size(); i < sz - 1; ++ i){
		ans = std::max(ans, vec[i + 1] - vec[i] - 1);
	}
	return printf("%I64d\n", ans), 0;
}