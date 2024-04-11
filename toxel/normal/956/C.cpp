#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;

int m[N], suf[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &m[i]);
	}
	suf[n + 1] = INT_MIN;
	for (int i = n; i; -- i){
		suf[i] = std::max(suf[i + 1], m[i] + 1 - i);
	}
	ll ans = 0, now = 1;
	for (int i = 2; i <= n; ++ i){
		if (now - i < suf[i]){
			++ now;
		}
		ans += now - m[i] - 1;
	}
	printf("%I64d\n", ans);
	return 0;
}