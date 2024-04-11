#include<bits/stdc++.h>
#define ll long long

const int N = 200010;

int n, m, k, x, s;
int a[N], b[N], c[N], d[N];
std::map <int, int, std::greater <int>> Hash;

int main(){
	scanf("%d%d%d%d%d", &n, &m, &k, &x, &s);
	for (int i = 0; i < m; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++ i){
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < k; ++ i){
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < k; ++ i){
		scanf("%d", &d[i]);
		Hash[d[i]] = c[i];
	}
	ll ans = 1ll * n * x;
	auto u = Hash.lower_bound(s);
	if (u != Hash.end()){
		ans = std::min(1ll * (n - u -> second) * x, ans);
	}
	for (int i = 0; i < m; ++ i){
		auto u = Hash.lower_bound(s - b[i]);
		if (u == Hash.end()){
			if (b[i] <= s){
				ans = std::min(1ll * n * a[i], ans);
			}
			continue;
		}
		ans = std::min(1ll * (n - u -> second) * a[i], ans);
	}
	return printf("%I64d\n", ans), 0;
}