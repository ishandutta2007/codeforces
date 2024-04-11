#include<bits/stdc++.h>
 
const int N = 600010;
const int moder = 1e9 + 7;

int min[N], phi[N], sum[N], power[N], fac[N], inv[N];
std::vector <int> prime;
char a[N], b[N];
int n;

int powermod(int a, int exp){
	int ret = 1;
	for ( ; exp; exp >>= 1){
		if (exp & 1){
			ret = 1ll * a * ret % moder;
		}
		a = 1ll * a * a % moder;
	}
	return ret;
}

int comb(int n, int m){
	return 1ll * fac[n] * inv[m] % moder * inv[n - m] % moder;
}

int main(){
	phi[1] = sum[1] = power[0] = fac[0] = 1;
	for (int i = 1; i < N; ++ i){
		fac[i] = 1ll * fac[i - 1] * i % moder;
		power[i] = 2 * power[i - 1] % moder;
	}
	inv[N - 1] = powermod(fac[N - 1], moder - 2);
	for (int i = N - 1; i; -- i){
		inv[i - 1] = 1ll * inv[i] * i % moder;
	}
	for(int i = 2; i < N; ++ i){
		if(!min[i]){
			prime.push_back(i);
			phi[i] = i - 1;
			min[i] = i;
		}
		for(int j = 0, k, sz = (int) prime.size(); j < sz && i * prime[j] < N; ++ j){
			min[k = i * prime[j]] = prime[j];
			if(i % prime[j] == 0){
				phi[k] = phi[i] * prime[j];
				break;
			}
			phi[k] = phi[i] * (prime[j] - 1);
		}
		sum[i] = (sum[i - 1] + phi[i]) % moder;
	}
	scanf("%s%s%d", a, b, &n);
	int lena = strlen(a), lenb = strlen(b);
	int cnt = lena == lenb ? 1 : 0, aa = 0, ab = 0, ba = 0, bb = 0;
	for (int i = 0, sz = std::max(lena, lenb); i < sz; ++ i){
		if (a[i] == '?' && b[i] == '?'){
			cnt = 2 * cnt % moder;
		}
		else if (a[i] != '?' && b[i] != '?' && a[i] != b[i]){
			cnt = 0;
		}
		if (a[i] == 'A'){
			++ aa;
		}
		if (a[i] == 'B'){
			++ ab;
		}
		if (b[i] == 'A'){
			++ ba;
		}
		if (b[i] == 'B'){
			++ bb;
		}
	}
	int y = (power[n + 1] - 2 + moder) % moder;
	int ans = 1ll * cnt * y % moder * y % moder;
	int ac = lena - aa - ab, bc = lenb - ba - bb;
	if (lena == lenb){
		int x = 0;
		for (int i = 1; i <= n; ++ i){
			x = ((x + 1ll * power[i] * (2 * sum[n / i] - 1)) % moder + moder) % moder;
		}
		int _cnt = 0;
		for (int i = 0; i <= ac; ++ i){
			if (aa + i - ba >= 0 && aa + i - ba <= bc){
				_cnt = (_cnt + 1ll * comb(ac, i) * comb(bc, aa + i - ba)) % moder;
			}
		}
		ans = (ans + 1ll * (_cnt - cnt + moder) * x) % moder;
	}
	int u = aa - ba, v = ab + ac - bb - bc;
	for (int i = -bc; i <= ac; ++ i){
		if (1ll * (u + i) * (v - i) < 0){
			int _u = std::abs(u + i), _v = std::abs(v - i);
			int gcd = std::__gcd(_u, _v);
			_u /= gcd;
			_v /= gcd;
			int x = u + v ? power[n / std::max(_u, _v) + 1] : power[n + 1];
			x = (x - 2 + moder) % moder;
			ans = (ans + 1ll * x * comb(ac + bc, i + bc)) % moder;
		}
	}
	return printf("%d\n", ans), 0;
}