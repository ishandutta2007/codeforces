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
int a, b, c;
string s;
char res[110];

int main () {
	int tt;
	cin >> tt;
	for (int it = 0; it < tt; it++) {
		cin >> n >> a >> b >> c;
		cin >> s;
		int aa = 0, bb = 0, cc = 0;
		for (int i = 0; i < n; i++) {
			aa += int (s[i] == 'R');
			bb += int (s[i] == 'P');
			cc += int (s[i] == 'S');
		}
		if (min (a, cc) + min (b, aa) + min (c, bb) >= (n + 1) / 2) {
			for (int i = 0; i < n; i++) res[i] = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == 'R' && b > 0) {
					res[i] = 'P';
					b--;
				} else
				if (s[i] == 'P' && c > 0) {
					res[i] = 'S';
					c--;
				} else
				if (s[i] == 'S' && a > 0) {
					res[i] = 'R';
					a--;
				}
			}	
			for (int i = 0; i < n; i++) {
				if (res[i]) continue;
				if (b > 0) {
					res[i] = 'P';
					b--;
				} else
				if (c > 0) {
					res[i] = 'S';
					c--;
				} else
				if (a > 0) {
					res[i] = 'R';
					a--;
				}
			}	
			printf ("YES\n");
			for (int i = 0; i < n; i++) printf ("%c", res[i]);
			printf ("\n");
		} else {
			printf ("NO\n");
		}
	}
	re 0;
}