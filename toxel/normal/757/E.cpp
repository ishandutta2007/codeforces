#include<bits/stdc++.h>
#define ll long long

const int N = 1000010;
const int moder = 1e9 + 7;

int min[N], fac[N << 1], inv[N << 1];
std::vector <int> prime;
std::map <int, int> fact;

int power_mod(int a, int index){
	int ans = 1;
	while (index){
		if (index & 1){
			ans = 1ll * ans * a % moder;
		}
		a = 1ll * a * a % moder;
		index >>= 1;
	}
	return ans;
}

void get_fact(int &n){
	for (ll i = 0; i < prime.size(); ++ i){
		ll x = prime[i];
		if (x * x > n)
			break;
		if (!(n % x)){
			++ fact[x];
			n /= x;
			return;
		}
	}
	++ fact[n];
	n = 1;
}

int comb(int n, int m){
	if (n < m || m < 0){
		return 0;
	}
	return 1ll * fac[n] * inv[m] % moder * inv[n - m] % moder;
}

int calc(int s, int r){
	if (!r){
		return 2;
	}
	++ s;
	int ans = 2ll * comb(s + r - 2, r) % moder;
	ans = (ans + comb(s + r - 2, r - 1)) % moder;
	return ans;
}

int q, r, n;

int main(){
	fac[0] = 1;
	for (int i = 1; i < N << 1; ++ i){
		fac[i] = 1ll * fac[i - 1] * i % moder;
	}
	inv[(N << 1) - 1] = power_mod(fac[(N << 1) - 1], moder - 2);
	for (int i = N - 1 << 1; i >= 0; -- i){
		inv[i] = 1ll * inv[i + 1] * (i + 1) % moder;
	}
	for (int i = 2; i < N; ++ i){
		if (!min[i]){
			min[i] = i;
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() && prime[j] <= i; ++ j){
			if (prime[j] * i >= N)
				break;
			min[prime[j] * i] = prime[j];
		}
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++ i){
		fact.clear();
		scanf("%d%d", &r, &n);
		int x = n;
		while (x > 1){
			get_fact(x);
		}
		int ans = 1;
		for (auto u = fact.begin(); u != fact.end(); ++ u){
			ans = 1ll * ans * calc(u -> second, r) % moder;
		}
		printf("%d\n", ans);
	}
	return 0;
}