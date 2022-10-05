#include<bits/stdc++.h>

typedef long long ll;

int main(){
	std::map <int, int> Hash;
	int n;
	scanf("%d", &n);
	for (int i = 0, a, x; i < n; ++ i){
		scanf("%d%d", &a, &x);
		Hash[a] = std::max(Hash[a], x);
	}
	int m;
	scanf("%d", &m);
	for (int i = 0, a, x; i < m; ++ i){
		scanf("%d%d", &a, &x);
		Hash[a] = std::max(Hash[a], x);
	}
	ll ans = 0;
	for (auto u : Hash){
		ans += u.second;
	}
	printf("%I64d\n", ans);
	return 0;
}