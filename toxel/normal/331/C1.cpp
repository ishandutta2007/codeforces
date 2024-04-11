#include<bits/stdc++.h>
#define ll long long

std::map <std::pair <int, ll>, std::pair <ll, int>> Hash;

std::pair <ll, int> dfs(std::pair <int, ll> p){
	ll power = 1, x = p.second;
	for ( ; x >= 10; power *= 10, x /= 10);
	if (!p.first && !p.second){
		return {0, 0};
	}
	if (power == 1){
		if (p.first){
			if (p.first > p.second){
				return {1, p.second - p.first};
			}
			else{
				return {2, -p.first};
			}
		}
		else{
			return {1, 0};
		}
	}
	if (Hash.count(p)){
		return Hash[p];
	}
	ll ret = 0;
	while (p.second >= 0){
		if (!p.first && !p.second){
			break;
		}
		x = std::max(1ll * p.first, p.second / power);
		std::pair <ll, int> pp = dfs({(int) x, p.second % power});
		p.second = p.second / power * power + pp.second;
		ret += pp.first;
	}
	return Hash[p] = {ret, p.second};
}

int main(){
	ll n;
	scanf("%I64d", &n);
	return printf("%I64d\n", dfs({0, n}).first), 0;
}