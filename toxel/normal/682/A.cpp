#include<bits/stdc++.h>

const int N = 100;

int cnt[N];
int n, m;

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i){
		++ cnt[i % 5];
	}
	long long ans = 0;
	for (int i = 1; i <= m; ++ i){
		ans += cnt[(5 - i % 5) % 5];
	}
	return printf("%I64d\n", ans), 0;
}