#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

std::pair <std::pair <int, int>, int> p[N];
int n;
ll dp[N];
std::set <std::pair <int, int>, std::greater <std::pair<int, int>>> set;
std::multiset <ll, std::greater <ll>> dp_set;

int main(){
	scanf("%d", &n);
	for (int i = 0, x, y, z; i < n; ++ i){
		scanf("%d%d%d", &x, &y, &z);
		p[i] = {{y, x}, z};
	}
	std::sort(p, p + n, std::greater <std::pair<std::pair <int, int>, int>>());
	for (int i = 0; i < n; ++ i){
		while (set.size()){
			auto u = set.begin();
			if ((*u).first >= p[i].first.first){
				auto v = dp_set.lower_bound(dp[(*u).second]);
				dp_set.erase(v);
				set.erase(u);
			}
			else{
				break;
			}
		}
		if (dp_set.size()){
			auto u = dp_set.begin();
			dp[i] = *u + p[i].second;
		}
		else{
			dp[i] = p[i].second;
		}
		set.insert({p[i].first.second, i});
		dp_set.insert(dp[i]);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++ i){
		ans = std::max(ans, dp[i]);
	}
	return printf("%I64d\n", ans), 0;
}