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

int n;
int m;
string s;
int res[100010];

int main () {
	cin >> s;
	n = sz (s);
	int one = 0, zero = 0;
	for (int i = n - 1; i >= 0; i--) {
//		if (s[i] == '1' && max (zero, one + 1) == max (zero + 1, one + 1)) s[i] = '0';
		if (s[i] == '0') {
			zero = max (zero + 1, one + 1);
		} else {
			one++;
		}
		res[i] = max (one, zero);
	}
	one = zero = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '1' && max (zero + 1, one + 1) == res[i]) s[i] = '0';
		if (s[i] == '0') {
			zero = max (zero + 1, one + 1);
		} else {
			one++;
		}
	}
	cout << s << endl;
	re 0;
}