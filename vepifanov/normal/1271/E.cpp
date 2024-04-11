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

ll n;
ll k;

ll calc (ll n, ll k) {
	int t = 0;
	ll s = 0;
	ll cur = 1;
	while (cur < k) {
		t++;
		if (cur + (1LL << t) >= k) {
			s = k - cur - 1;
			break;
		}
		cur += 1LL << t;
	}
//	cout << ((n - s) >> t) << endl;
	re ((n - s) >> t);
}

ll calc2 (ll n, ll k) {
	int t = 0;
	ll s = 1;
	ll cur = 2;
	if (cur >= k) t++;
	while (cur < k) {
		t++;
		if (cur + (1LL << t) + (1LL << t) >= k) {
			t++;
			s = k - cur - 1;
			break;
		}
		cur += 2LL << t;
	}
//	cout << t << " " << s << endl;
	ll res = ((n - s) >> t) * 2;
	re res;
}

int main () {
	cin >> n >> k;
	cout << max (calc (n, k), calc2 (n, k)) << endl;
	re 0;
}