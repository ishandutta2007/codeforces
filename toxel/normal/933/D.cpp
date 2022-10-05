#include<bits/stdc++.h>

const int moder = 1e9 + 7;
typedef long long ll;

int powermod(int a, int exp){
	int ret = 1;
	for ( ; exp > 0; exp >>= 1){
		if (exp & 1){
			ret = 1ll * ret * a % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

const int N = 10;
int inv[N];

int sum0(ll n){
	return n % moder;
}

int sum1(ll n){
	int x = n % moder;
	return 1ll * x * (x + 1) % moder * inv[2] % moder;
}

int sum2(ll n){
	int x = n % moder;
	return 1ll * x * (x + 1) % moder * (2 * x + 1) % moder * inv[6] % moder;
}

int sum3(ll n){
	int x = sum1(n);
	return 1ll * x * x % moder;
}

int sum0(int type, ll l, ll r){
	if (l > r) return 0;
	int ret = (sum0(r) - sum0(l - 1)) % moder;
	ret += ret < 0 ? moder : 0;
	return ret;
}

int sum1(int type, ll l, ll r){
	if (l > r) return 0;
	int ret;
	if (type == 1){
		ret = 4ll * (sum1(r) - sum1(l - 1)) % moder;
		ret = (ret + 1ll * (sum0(r) - sum0(l - 1))) % moder;
		ret += ret < 0 ? moder : 0;
	}
	else{
		ret = 4ll * (sum1(r) - sum1(l - 1)) % moder;
		ret = (ret + 3ll * (sum0(r) - sum0(l - 1))) % moder;
		ret += ret < 0 ? moder : 0;
	}
	return ret;
}

int sum2(int type, ll l, ll r){
	if (l > r) return 0;
	int ret;
	if (type == 1){
		ret = 16ll * (sum2(r) - sum2(l - 1)) % moder;
		ret = (ret + 8ll * (sum1(r) - sum1(l - 1))) % moder;
		ret = (ret + 1ll * (sum0(r) - sum0(l - 1))) % moder;
		ret += ret < 0 ? moder : 0;
	}
	else{
		ret = 16ll * (sum2(r) - sum2(l - 1)) % moder;
		ret = (ret + 24ll * (sum1(r) - sum1(l - 1))) % moder;
		ret = (ret + 9ll * (sum0(r) - sum0(l - 1))) % moder;
		ret += ret < 0 ? moder : 0;
	}
	return ret;
}

int sum3(int type, ll l, ll r){
	if (l > r) return 0;
	int ret;
	if (type == 1){
		ret = 64ll * (sum3(r) - sum3(l - 1)) % moder;
		ret = (ret + 48ll * (sum2(r) - sum2(l - 1))) % moder;
		ret = (ret + 12ll * (sum1(r) - sum1(l - 1))) % moder;
		ret = (ret + 1ll * (sum0(r) - sum0(l - 1))) % moder;
		ret += ret < 0 ? moder : 0;
	}
	else{
		ret = 64ll * (sum3(r) - sum3(l - 1)) % moder;
		ret = (ret + 144ll * (sum2(r) - sum2(l - 1))) % moder;
		ret = (ret + 108ll * (sum1(r) - sum1(l - 1))) % moder;
		ret = (ret + 27ll * (sum0(r) - sum0(l - 1))) % moder;
		ret += ret < 0 ? moder : 0;
	}
	return ret;
}

int main(){
	for (int i = 1; i < N; ++ i){
		inv[i] = powermod(i, moder - 2);
	}
	ll m;
	scanf("%I64d", &m);
	int coe0 = 1ll * (sum1(m) + sum2(m)) * inv[2] % moder;
	int coe1 = (inv[6] + ((m + 1) % moder) * inv[2]) % moder;
	int coe2 = ((-m - 2) % moder) * inv[2] % moder;
	coe2 += coe2 < 0 ? moder : 0;
	int coe3 = inv[3];
	int ans0 = 0, ans1 = 0, ans2 = 0, ans3 = 0;
	for (ll i = 1, j; i <= m; i = j + 1){
		j = m / (m / i);
		int x = sum0(1, i + 2 >> 2, j - 1 >> 2) - sum0(0, i >> 2, j - 3 >> 2);
		x += x < 0 ? moder : 0;
		ans0 = (ans0 + 1ll * sum0(m / i) * x) % moder;
		x = sum1(1, i + 2 >> 2, j - 1 >> 2) - sum1(0, i >> 2, j - 3 >> 2);
		x += x < 0 ? moder : 0;
		ans1 = (ans1 + 1ll * sum1(m / i) * x) % moder;
		x = sum2(1, i + 2 >> 2, j - 1 >> 2) - sum2(0, i >> 2, j - 3 >> 2);
		x += x < 0 ? moder : 0;
		ans2 = (ans2 + 1ll * sum2(m / i) * x) % moder;
		x = sum3(1, i + 2 >> 2, j - 1 >> 2) - sum3(0, i >> 2, j - 3 >> 2);
		x += x < 0 ? moder : 0;
		ans3 = (ans3 + 1ll * sum3(m / i) * x) % moder;
	}
	int ans = (1ll * ans0 * coe0 + 1ll * ans1 * coe1 + 1ll * ans2 * coe2 + 1ll * ans3 * coe3) % moder;
	ans = 4ll * ans % moder;
	ans += coe0;
	ans -= ans >= moder ? moder : 0;
	printf("%d\n", ans);
	return 0;
}