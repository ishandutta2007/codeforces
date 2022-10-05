#include<bits/stdc++.h>

const int N = 20;

int cnt[N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		++ cnt[x];
	}
	long long ans = 1ll * n * n;
	for (int i = 1; i <= m; ++ i){
		ans -= 1ll * cnt[i] * cnt[i];
	}
	return printf("%I64d\n", ans >> 1), 0;
}