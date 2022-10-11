#include <iostream>
#include <cstdio>
#include <map>

typedef long long ll;

ll fexp(ll x, ll e, ll mod) {
	ll ans = 1;
	x %= mod;
	e = (e % (mod - 1) + mod - 1) % (mod - 1);
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % mod;
		}
		x = x * x % mod;
	}
	return ans;
}

//is n primitive root of p ?
bool test(ll x, ll p) {
	ll m = p - 1;
	for(int i = 2; i * i <= m; ++i) if(m % i == 0) {
		if(fexp(x, i, p) == 1) return false;
		if(fexp(x, m / i, p) == 1) return false;
	}
	return true;
}

//find the largest primitive root for p
ll search(ll p) {
	for(ll i = p - 1; i >= 2; --i) if(test(i, p)) return i;
	return -1;
}

ll modinverse(ll a, ll b, ll s0 = 1, ll s1 = 0) {
    if(!b) {
        return s0;
    } else {
        return modinverse(b, a % b, s1, s0 - s1 * (a / b));
    }
}

int getPrime(int n) {
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			while(n % i == 0) n /= i;
			if(n == 1) return i;
			else return -1;
		}
	}
	return n;
}

int main() {
	int n;
	std::cin >> n;
	if(n == 1) {
		std::cout << "YES\n1\n";
		return 0;
	} else if(n == 4) {
		std::cout << "YES\n1\n3\n2\n4\n";
		return 0;
	} else if(n == 2) {
		std::cout << "YES\n1\n2\n";
		return 0;
	}
	int p = getPrime(n);
	if(p != n) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
		int root = search(p);
		int cur = 1;
		int num = 1;
		/*for(int i = 0; i + 1 < p; i++) {
			printf("%d\n", num);
			cur = (ll) cur * root % n;
			num = (ll) num * cur % n;
		}*/
		std::cout << "1\n";
		for(int i = 1; i <= p / 2; i++) {
			printf("%d\n", fexp(root, 2 * i - 1, p));
			//cur = cur * fexp(root, 2 * i - 1, p) % n;
			//std::cout << cur << std::endl;
			if(i == p / 2) continue;
			printf("%d\n", fexp(root, p - 2 * i - 1, p));
			//cur = cur * fexp(root, -2 * i, p) % n;
			//std::cout << cur << std::endl;
			//std::cout << (2 * i - 1) % (p - 1) << ' ' << ((-2 * i) % (p - 1) + p - 1) % (p - 1) << std::endl;
		}
		printf("%d\n", p);
	}
}