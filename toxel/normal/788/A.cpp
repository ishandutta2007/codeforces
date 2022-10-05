#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

int a[N], _abs[N], n;
std::multiset <ll> set = {0};
ll pre[N];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		_abs[i] = std::abs(a[i - 1] - a[i]);
	}
	for (int i = 1; i < n; ++ i){
		pre[i] = pre[i - 1] + (i & 1 ? _abs[i] : -_abs[i]);
		set.insert(pre[i]);
	}
	ll ans = -LLONG_MAX;
	for (int i = 0; i < n - 1; ++ i){
		auto u = set.find(pre[i]);
		set.erase(u);
		if (i & 1){
			auto u = set.begin();
			ans = std::max(pre[i] - *u, ans);
		}
		else{
			auto u = set.end();
			-- u;
			ans = std::max(*u - pre[i], ans);
		}
	}
	return printf("%I64d\n", ans), 0;
}