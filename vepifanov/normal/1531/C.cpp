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
string s[100];

int main () {
	scanf ("%d", &n);
	if (n == 2) {
		printf ("-1\n");
		re 0;
	}
	int m = 1;
	while (m * m < n) m++;
	for (int i = 0; i < m; i++) s[i] = string (m, 'o');
	if (m * m > n) {
		if ((m * m - 1) % 2 == n % 2) {
			s[m - 1][m - 1] = '.';
			int rem = (m * m - 1 - n) / 2;
			for (int i = 0; i < rem; i++) s[m - 1][m - i - 2] = s[m - i - 2][m - 1] = '.';			
		} else {
			if (n == m * m - 2) {
				s[m - 1][m - 1] = '.';
				s[m - 2][m - 2] = '.';
				s[m - 1][m - 2] = '.';
				s[m - 2][m - 1] = '.';
				s[0] += 'o';
				for (int i = 1; i < m; i++) s[i] += '.';
				s[m] = "o" + string (m, '.');
				m++;
			} else {
				s[m - 1][m - 1] = '.';
				s[m - 2][m - 2] = '.';
				int rem = (m * m - 2 - n) / 2;
				for (int i = 0; i < rem; i++) s[m - 1][m - i - 2] = s[m - i - 2][m - 1] = '.';			
			}
		}
	}
	cout << m << endl;
	for (int i = 0; i < m; i++) cout << s[m - i - 1] << endl;
	re 0;
}