#include <iostream>
#include <utility>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if(b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

pair<ll, ll> euclides(ll a, ll b) {
	a = max(a, -a);
	b = max(b, -b);
	ll u = 0, oldu = 1;
	ll v = 1, oldv = 0;
	while(b != 0) {
		ll q = a / b;
		oldv = oldv - v * q;
		oldu = oldu - u * q;
		a = a - b * q;
		swap(a, b);
		swap(u, oldu);
		swap(v, oldv);
	}
	return pair<ll, ll>(oldu, oldv);
}

int main() {
	ll a, b, c;
	std::cin >> a >> b >> c;
	c = -c;
	ll g = gcd(max(a, -a), max(b, -b));
	if(c % g != 0) {
		cout << "-1\n";
		return 0;
	}
	auto p = euclides(max(a, -a), max(b, -b));
	if(a < 0) p.first = -p.first;
	if(b < 0) p.second = -p.second;
	p.first *= c / g;
	p.second *= c / g;
	cout << p.first << ' ' << p.second << endl;
}