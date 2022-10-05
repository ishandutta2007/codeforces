#include<bits/stdc++.h>

const int N = 100010;
const int moder = 1e9 + 9;

char s[N];

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

int main(){
	int n, a, b, k;
	scanf("%d%d%d%d%s", &n, &a, &b, &k, s);
	int ans = 0, sum = 0;
	for (int i = 0; i < k; ++ i){
		sum = (sum + (s[i] == '+' ? 1ll : -1ll) * powermod(a, n - i) * powermod(b, i)) % moder;
		sum += sum < 0 ? moder : 0;
	}
	int exp = (n + 1) / k;
	if (powermod(a, k) == powermod(b, k)){
		ans = 1ll * sum * exp % moder;
	}
	else{
		int bdiva = 1ll * b * powermod(a, moder - 2) % moder;
		int tmp = 1 - powermod(bdiva, k);
		tmp += tmp < 0 ? moder : 0;
		tmp = powermod(tmp, moder - 2);
		ans = 1ll * (1 - powermod(bdiva, k * exp)) * tmp % moder * sum % moder;
		ans += ans < 0 ? moder : 0;
	}
 	for (int i = (n + 1) / k * k; i <= n; ++ i){
		ans = (ans + 1ll * powermod(a, n - i) * powermod(b, i)) % moder;
	}
	printf("%d\n", ans);
	return 0;
}