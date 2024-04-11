#include<bits/stdc++.h>

#define ll long long
#define sqr(x) ((x) * (x))

int n, c1, c2;
int cnt[2];

int main(){
	scanf("%d%d%d", &n, &c1, &c2);
	getchar();
	for (int i = 0; i < n; ++ i){
		char ch = getchar();
		++ cnt[ch - '0'];
	}
	ll min = LLONG_MAX;
	for (int i = 1; i <= cnt[1]; ++ i){
		ll x = n / i, y = n - x * i;
		min = std::min(1ll * c1 * i + c2 * (y * sqr(x) + (i - y) * sqr(x - 1)), min);
	}
	return printf("%I64d\n", min), 0;
}