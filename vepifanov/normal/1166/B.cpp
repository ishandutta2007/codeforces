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

const string sym = "aeiou";

int n;
int m;

int main () {
	cin >> n;
	for (int i = 5; i * i <= n; i++)
		if (n % i == 0) {
			for (int a = 0; a < i; a++)
				for (int b = 0; b < n / i; b++)
					printf ("%c", sym[(a + b) % 5]);
			printf ("\n");
			re 0;
		}
	printf ("-1\n");
	re 0;
}