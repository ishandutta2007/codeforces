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
int m;
string s;
int res[100100];

int main () {
	cin >> s;
	n = sz (s);
	res[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		res[i] = 0;
		if (s[i] != 'w' && s[i] != 'm') res[i] = res[i + 1];
		if (i + 2 <= n && s[i] == s[i + 1] && (s[i] == 'u' || s[i] == 'n')) res[i] = (res[i] + res[i + 2]) % mod;
	}
	printf ("%d\n", res[0]);
	re 0;
}