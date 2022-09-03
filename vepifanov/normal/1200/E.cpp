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

const int mod = 998244353;

int n;
int m;

string s[100000];
char h[1000010];
int ht[1000010];
int htt[1000010];
char sym[1000010];
int pw[1000010];

int geth (int* ht, int i, int j) {
	re (ht[j] - ((ll)ht[i] * pw[j - i]) % mod + mod) % mod;
}

void add (int* ht, int& o, int i, int j, bool addsym = true) {
	for (int k = j; k < sz (s[i]); k++) {
	    if (addsym) sym[o] = s[i][k];
		ht[o + 1] = ((ll)ht[o] * 239 + s[i][k]) % mod;
		o++;
	}
}

int main () {
	pw[0] = 1;
	for (int i = 1; i < 1000010; i++) pw[i] = ((ll)pw[i - 1] * 239) % mod;

	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf (" %s", h);
		s[i] = string (h);
	}
	int o = 0;
	ht[0] = 0;
	add (ht, o, 0, 0);
	for (int i = 1; i < n; i++) {
		int e = 0;
		add (htt, e, i, 0, false);
		for (int j = min (o, e); j >= 0; j--)
			if (geth (ht, o - j, o) == geth (htt, 0, j)) {
				add (ht, o, i, j);
				break;
			}
	}
	sym[o] = '\0';
	printf ("%s\n", sym);
	re 0;
}