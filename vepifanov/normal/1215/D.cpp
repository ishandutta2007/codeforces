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

int main () {
	cin >> n >> s;
	int bal = 0, cp = 0, cn = 0;
	for (int i = 0; i < n; i++)
		if (2 * i < n) {
			if (s[i] == '?') cp++; else bal += s[i] - '0';
		} else {
			if (s[i] == '?') cn++; else bal -= s[i] - '0';
		}
	if ((cp + cn) & 1) printf ("Monocarp\n"); else {
		if (bal < 0) {
			bal = -bal;
			swap (cp, cn);
		}
		if (cp > cn) printf ("Monocarp\n"); else {
			cn -= cp;
			if (bal == 9 * (cn / 2)) printf ("Bicarp\n"); else printf ("Monocarp\n");
		}
	}
	re 0;
}
/*
111111111111111110111111111111111111111111111111111 M
000000000000000001111111111000000000000000000000000 B
111111111111111111111111110111111111111111111111111 M
000000000000000000000000001111111111000000000000000 B
111111111111111111111111111111111110111111111111111 M
*/