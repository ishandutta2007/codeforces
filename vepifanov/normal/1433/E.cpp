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
ll f[21];

ll cnk (int n, int k) {
	if (n < 0 || k < 0 || k > n) re 0;
	re f[n] / f[n - k] / f[k];
}

int main () {
	f[0] = 1;
	for (int i = 1; i <= 20; i++) f[i] = f[i - 1] * i;
	cin >> n;
	m = n / 2;
	cout << cnk (n - 1, m - 1) * f[m - 1] * f[m - 1] << endl;
	re 0;
}