#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

const int mod = 1000*1000*1000+7;

int n;
ll m;
vi p;

int power (int a, ll b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

int main () {
	cin >> n >> m;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
        	p.pb (i);
        	while (n % i == 0) n /= i;
		}
	if (n > 1) p.pb (n);
	int ans = 1;
	for (int i = 0; i < sz (p); i++) {
		ll mm = m;
		while (mm >= p[i]) {
			mm /= p[i];
			ans = ((ll)ans * power (p[i], mm)) % mod;
		}
	}
	printf ("%d\n", ans);
	re 0;
}