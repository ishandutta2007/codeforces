#include<bits/stdc++.h>

const int moder = 1e9 + 7;
typedef long long ll;
typedef std::pair <int, int> pii;

int powermod(int a, int exp, int moder){
	int ret = 1;
	for ( ; exp > 0; exp >>= 1){
		if (exp & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

const int N = 5010;

int comb[N][N];
int power[N], a[N], b[N];

int main(){
	for (int i = 0; i < N; ++ i){
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++ j){
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
			comb[i][j] -= comb[i][j] >= moder ? moder : 0;
		}
	}
	std::vector <pii> vec;
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < N; ++ i){
		power[i] = powermod(i, k, moder);
	}
	for (int i = 0; i <= k; ++ i){
		int ans = 0;
		for (int j = 0; j <= i; ++ j){
			ans = (ans + 1ll * comb[i][j] * power[j]) % moder;
		}
		if (i == n){
			printf("%d\n", ans);
			return 0;
		}
		ans = 1ll * ans * powermod(powermod(2, i, moder), moder - 2, moder) % moder;
		vec.push_back({i, ans});
	}
	a[0] = 1;
	int len = 0;
	for (int i = 0; i <= k; ++ i){
		for (int j = len; j >= 0; -- j){
			a[j + 1] += a[j];
			a[j + 1] -= a[j + 1] >= moder ? moder : 0;
			a[j] = 1ll * a[j] * (moder - vec[i].first) % moder;
		}
		++ len;
	}
	int ret = 0, value = 0;
	for (int i = 0, now = 1; i <= k + 1; ++ i){
		value = (value + 1ll * a[i] * now) % moder;
		now = 1ll * now * n % moder;
	}
	for (int i = 0; i <= k; ++ i){
		int x = 1ll * value * powermod(n - vec[i].first, moder - 2, moder) % moder;
		int y = 1;
		for (int j = 0; j <= k; ++ j){
			if (i == j) continue;
			y = 1ll * y * (vec[i].first - vec[j].first) % moder;
			y += y < 0 ? moder : 0;
		}
		x = 1ll * x * powermod(y, moder - 2, moder) % moder;
		ret = (ret + 1ll * x * vec[i].second) % moder;
	}
	ret = 1ll * ret * powermod(2, n, moder) % moder;
	printf("%d\n", ret);
	return 0;
}