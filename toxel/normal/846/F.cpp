#include<bits/stdc++.h>

const int N = 1000010;
typedef long long ll;

std::vector <int> vec[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1, x; i <= n; ++ i){
		scanf("%d", &x);
		vec[x].push_back(i);
	}
	ll total = 0;
	for (int i = 0; i < N; ++ i){
		if (!vec[i].size()){
			continue;
		}
		total += 1ll * n * n;
		int pre = 0;
		for (auto u : vec[i]){
			total -= 1ll * (u - pre - 1) * (u - pre - 1);
			pre = u;
		}
		total -= 1ll * (n - pre) * (n - pre);
	}
	return printf("%.10lf\n", 1.0 * total / (1ll * n * n)), 0;
}