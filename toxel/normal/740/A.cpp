#include<bits/stdc++.h>
#define ll long long

int n, a, b, c;

int main(){
	scanf("%d%d%d%d", &n, &a, &b, &c);
	ll ans = LLONG_MAX;
	for (int i = 0; i <= 3; ++ i)
		for (int j = 0; j <= 3; ++ j)
			for (int k = 0; k <= 3; ++ k){
				if ((n + i + 2 * j + 3 * k) % 4)
					continue;
				ll x = 1ll * i * a + 1ll * j * b + 1ll * k * c;
				ans = std::min(x, ans);
			}
	printf("%I64d\n", ans);
	return 0;
}