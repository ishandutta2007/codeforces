#include<bits/stdc++.h>

const int N = 5000010;
const int moder = 1e9 + 7;
typedef long long ll;

ll dp[N];
int t, l, r;

int main(){
	memset(dp, 0x7f, sizeof(dp));
	dp[1] = 0;
	for (int i = 1; i < N; ++ i){
		for (int j = i << 1; j < N; j += i){
			dp[j] = std::min(dp[j], dp[i] + (1ll * j * (j / i - 1) >> 1));
		}
	}
	scanf("%d%d%d", &t, &l, &r);
	int now = 1, ans = 0;
	for (int i = l; i <= r; ++ i, now = 1ll * now * t % moder){
		ans = (ans + 1ll * now * (dp[i] % moder)) % moder;
	}
	return printf("%d\n", ans), 0;
}