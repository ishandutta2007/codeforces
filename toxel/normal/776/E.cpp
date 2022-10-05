#include<bits/stdc++.h>
#define ll long long

const int MODER = 1e9 + 7;

ll long_mod(ll a, ll c, ll moder){
	const int orz = 1e9;
	ll b = a % orz, d = c % orz;
	a /= orz, c /= orz;
	ll ret = b * d % moder, ans = a * c % moder;
	for (int i = 0; i < 18; ++ i){
		ans = ans * 10 % moder;
	}
	ret = (ret + ans) % moder;
	ans = (a * d + b * c) % moder;
	for (int i = 0; i < 9; ++ i){
		ans = ans * 10 % moder;
	}
	return (ret + ans) % moder;
}	

ll power_mod(ll a, ll index, ll moder){
	ll ans = 1;
	while (index){
		if (index & 1)
			ans = long_mod(ans, a, moder);
		a = long_mod(a, a, moder);
		index >>= 1;
	}
	return ans;
}

ll random(ll n){
	ll ret = 1ll * rand() * rand() * rand() * rand() + 1ll * rand() * rand() * rand() + 1ll * rand() * rand() + rand() + 1;
	return ret % n;
}

bool Miller_Rabin(ll n, ll t, ll u){
	ll a = random(n);
	if(!a || a == 1)
		return true;
	ll pre = power_mod(a, u, n);
	for (int i = 0; i < t; ++ i){
		ll now = long_mod(pre, pre, n);
		if (now == 1 && pre != 1 && pre != n - 1)
			return false;
		pre = now;
	}
	return pre == 1;
}

bool miller_rabin(ll n){
	if (n <= 30)
		return n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || n == 23 || n == 29;
	if (!(n & 1))
		return false;
	const int S = 10;
	ll t = 0, x = n - 1;
	while (!(x & 1)){
		x /= 2;
		++ t;
	}
	for (int i = 0; i < S; ++ i){
		if (!Miller_Rabin(n, t, x))
			return false;
	}
	return true;
}

std::map <ll, int> fact;

ll pollard_rho(ll n){
	ll c = random(n - 1) + 1, x = random(n), y = x, i = 0, k = 1;
	while (true){
		++ i;
		x = long_mod(x, x, n);
		x = (x + c) % n;
		ll d = std::__gcd(std::abs(y - x), n);
		if (d != 1 && d != n){
			return d;
		}
		if (x == y){
			return n;
		}
		if (i == k){
			y = x;
			k <<= 1;
		}
	}
}

void get_fact(ll n){
	if (n == 1){
		return;
	}
	if (miller_rabin(n)){
		++ fact[n];
		return;
	}
	ll x = pollard_rho(n);
	get_fact(x);
	get_fact(n / x);
}

ll phi(ll n){
	ll ret = 1;
	fact.clear();
	get_fact(n);
	for (auto u = fact.begin(); u != fact.end(); ++ u){
		ret *= u -> first - 1;
		for (int i = 0; i < u -> second - 1; ++ i){
			ret *= u -> first;
		}
	}
	return ret;
}

int main(){
	srand((unsigned) time(NULL));
	ll n, k;
	scanf("%I64d%I64d", &n, &k);
	for (ll i = 0; i < k + 1 >> 1; ++ i){ 
		n = phi(n);
		if (n == 1){
			return printf("%I64d\n", n), 0;
		}
	}
	return printf("%I64d\n", n % MODER), 0;
}