#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> T sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

int n;
int m;
ll a1, b1, a2, b2, l, r;

ll power (ll a, ll b, ll mod) {
	ll c = 1;
	while (b) {
		if (b & 1) c = (c * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	re c;
}

ll phi (ll x) {
	ll cur = 1;
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) {
			ll tmp = 1;
			while (x % i == 0) {
				x /= i;
				tmp *= i;
			}
			cur *= tmp - tmp / i;
		}
	if (x > 1) cur *= x - 1;
	re cur;
}

ll up (ll p, ll q) {
	if (p % q == 0) re p / q;
	re p / q + int (p > 0);
}

ll mul (ll a, ll b, ll mod) {
	ll c = 0;
	while (b) {
		if (b & 1) c = (c + a) % mod;
		a = (a + a) % mod;
		b /= 2;
	}
	re c;
}

int main () {
	cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
	ll d = gcd (a1, a2);
	ll a = a1 * a2 / d;
	if ((b2 - b1) % d != 0) printf ("0\n"); else {
		ll p = (b2 - b1) / d;
		ll q = a1 / d;
		ll z = a2 / d;
		ll b = (mul (p * a1, power (q, phi (z) - 1, z), a) + b1) % a;
//		cout << p << " " << q << " " << z << " " << d << endl;
		ll t = max (up (b1 - b, a), up (b2 - b, a));
		l = max (l, a * t + b);
//		cout << a << " " << b << " " << t << " " << l << " " << r << " " << (a * t + b - b1) % a1 << " " << (a * t + b - b2) % a2 << " " << (r - b) / a << endl;
		if (l > r)
			cout << 0 << endl;
		else	
			cout << (r - b) / a - (l > a * t + b ? (l - b - 1) / a : t - 1) << endl;
	}
	return 0;
}