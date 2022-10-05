#include<bits/stdc++.h>

const int N = 31;
typedef long long ll;

ll c[N];
std::map <int, ll> Hash;

ll dfs(int n){
	if (Hash.count(n)){
		return Hash[n];
	}
	ll ans = LLONG_MAX;
	for (int i = 0; i < N; ++ i){
		if (1 << i >= n){
			ans = std::min(ans, c[i]);
		}
		else if (n - (1 << i) < 1 << i){
			ans = std::min(ans, c[i] + dfs(n - (1 << i)));
		}
	}
	return Hash[n] = ans;
}

int main(){
	int n, L;
	scanf("%d%d", &n, &L);
	for (int i = 0; i < n; ++ i){
		scanf("%I64d", &c[i]);
	}
	for (int i = 1; i < N; ++ i){
		if (!c[i] || c[i] > 2 * c[i - 1]){
			c[i] = c[i - 1] << 1;
		}
	}
	ll ans = dfs(L);
	printf("%I64d\n", ans);
	return 0;
}