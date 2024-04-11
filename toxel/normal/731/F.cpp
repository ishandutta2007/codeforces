#include<bits/stdc++.h>
#define ll long long

const int N = 800010;

int n, cnt[N];
ll pre[N];

int main(){
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		++ cnt[x];
	}
	for (int i = 0; i < N; ++ i){
		pre[i + 1] = pre[i] + cnt[i];
	}
	ll ans = 0;
	for (int i = 1; i < N >> 2; ++ i){
		if (!cnt[i]){
			continue;
		}
		ll sum = 0;
		for (int j = 0; j < N >> 2; j += i){
			sum += j * (pre[j + i] - pre[j]);
		}
		ans = std::max(ans, sum);
	}
	return printf("%I64d\n", ans), 0;
}