#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
#define vi vector<int>
typedef long long ll;	
using namespace std;

const int P = 1e9 + 7;

int T;
ll n;

int main() { 
	cin >> T;
	while (T--) {
		ll res = 0;
		cin >> n;
		ll lcm = 1, i = 2;
		while (lcm <= n) {
			int p = 0;
			for (int e = 2; e * e <= i; e++)
				if (i % e == 0) {
					p = e;
					break;
				}
			if (p == 0)
				p = i;
			ll x = i;
			while (x % p == 0)
				x /= p;
			if (x == 1) {
				ll cnt = (n / lcm - n / (lcm * p)) % P;
				res = (res + i * cnt) % P;
				lcm *= p;
			}
			i++;
		}
		cout << res << "\n";
	}
	return 0;
}