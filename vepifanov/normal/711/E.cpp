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

const int mod = 1000*1000+3;

ll n, m;

ll power (ll a, ll b) {
	ll c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

int main () {
	cin >> n >> m;
	if (n < 60 && ((ll)1 << n) < m) {
		printf ("1 1\n");
		re 0;
	}
	ll p2 = 0;
	for (ll i = 1; i <= n; i++)
		if (((ll)1 << i) > m) {
			p2 += n - i + 1;
			break;
		} else p2 += (m + ((ll)1 << i) - 1) >> i;
	ll q = power (power (2, n), m);
	ll rev2 = power (2, mod - 2);
	ll g = power (rev2, p2);
	q = (q * g) % mod;
	if (m >= mod) cout << q << " " << q << endl; else {
		ll a = power (2, n);
		ll p = 1;
		for (int i = 0; i < m; i++) p = (p * (a - i)) % mod;
		p = (p * g) % mod;
		p = (q - p + mod) % mod;
		cout << p << " " << q << endl;
	}
	return 0;
}