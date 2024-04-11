#include<bits/stdc++.h>
#define ll long long

const int N = 300010;
const int moder = 1e9 + 7;

int n;
int x[N], power[N], pre[N];

int main(){
	power[0] = 1;
	for (int i = 1; i < N; ++ i){
		power[i] = 2 * power[i - 1] % moder;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &x[i]);
	}
	std::sort(x + 1, x + n + 1);
	for (int i = 1; i <= n; ++ i){
		pre[i] = (pre[i - 1] + x[i]) % moder;
	}
	int ans = 0;
	for (int i = 1; i < n; ++ i){
		int x = (pre[n] - pre[i] + moder) % moder;
		x = (x - pre[n - i] + moder) % moder;
		ans = (ans + 1ll * x * power[i - 1]) % moder;
	}
	return printf("%d\n", ans), 0;
}