#include<bits/stdc++.h>

const int N = 2000010;
typedef long long ll;

ll cnt[N], sum[N];
int n, x, y;

ll getsum(int sit){
	return sit >= 0 ? sum[sit] : 0;
}

ll getcnt(int sit){
	return sit >= 0 ? cnt[sit] : 0;
}

int main(){
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		++ cnt[x];
		sum[x] += x;
	}
	for (int i = 1; i < N; ++ i){
		cnt[i] += cnt[i - 1];
		sum[i] += sum[i - 1];
	}
	ll ans = LLONG_MAX;
	for (int i = 2; i < N; ++ i){
		int max = std::min(x / y, i - 1);
		ll ret = 0;
		for (int j = 0; j + i < N; j += i){
			ret += ((getcnt(j + i - 1) - getcnt(j + i - max - 1)) * (j + i) - (getsum(j + i - 1) - getsum(j + i - max - 1))) * y;
			ret += (getcnt(j + i - max - 1) - getcnt(j)) * x;
		}
		ans = std::min(ans, ret);
	}
	return printf("%I64d\n", ans), 0;
}