#include <iostream>

typedef long long ll;

const int ms = 220;

int a[ms];
int dist[ms];

ll gcd(ll a, ll b) {
	if(!b) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	ll ans = 1;
	ll l = 1;
	for(int i = 1; i <= n; i++) {
		int on = a[i];
		int step = 1;
		while(on != i && on != a[on] && step < n + n) {
			step++;
			on = a[on];
		}
		if(on == i) {
			l = lcm(l, step);
			dist[i] = 1;
		} else {
			//ans = std::max(ans, (ll) step);
		}
	}
	for(int i = 1; i <= n; i++) {
		int on = a[i];
		int step = 1;
		while(!dist[on]) {
			step++;
			on = a[on];
		}
		ans = std::max(ans, (ll)step);
	}
	if(l < ans) {
		ll hmm = 0;
		while(hmm < ans) {
			hmm += l;
		}
		ans = hmm;
	}
	ans = std::max(ans, l);
	std::cout << ans << '\n';
}