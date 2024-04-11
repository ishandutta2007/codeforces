#include<bits/stdc++.h>
#define ll long long
#define __int128 long long

ll power_mod(ll a, ll index, ll moder){
	__int128 ans = 1;
	while (index){
		if (index & 1)
			ans = ans * a % moder;
		a = ((__int128) a) * a % moder;
		index >>= 1;
	}
	return ans;
}

ll random(ll n){
	ll ret = 1ll * rand() * rand() * rand() * rand() + 1ll * rand() * rand() * rand() + 1ll * rand() * rand() + rand() + 1;
	//std::cout << ret << std::endl;
	return ret % n;
}

bool Miller_Rabin(ll n, ll t, ll u){
	ll a = random(n);
	if(!a || a == 1)
		return true;
	ll pre = power_mod(a, u, n);
	for (int i = 0; i < t; ++ i){
		ll now = (__int128) pre * pre % n;
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

int main(){
	srand((unsigned) time(NULL));
	int n;
	scanf("%d", &n);
	if (miller_rabin(n)){
		return printf("1\n"), 0;
	}
	if (!(n & 1)){
		return printf("2\n"), 0;
	}
	if (miller_rabin(n - 2)){
		return printf("2\n"), 0;
	}
	return printf("3\n"), 0;
}