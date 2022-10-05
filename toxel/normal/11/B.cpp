#include<bits/stdc++.h>

typedef long long ll;

const int N = 50010;
ll x[N];

int main(){
	for (int i = 0; i < N; ++ i){
		x[i] = 1ll * i * (i + 1) >> 1;
	}
	ll n;
	scanf("%I64d", &n);
	n = std::abs(n);
	int y = std::lower_bound(x, x + N, n) - x;
	while (x[y] - n & 1){
		++ y;
	}
	return printf("%d\n", y), 0;
}