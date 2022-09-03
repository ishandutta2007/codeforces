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
char h[2010];
int cnt[26];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		scanf (" %s", h);
		for (int i = 0; i < 26; i++) cnt[i] = 0;
		for (int i = 0; h[i]; i++) cnt[h[i] - 'a']++;
		for (int len = n; len >= 1; len--) {
			int d = len / gcd (len, m);
			int can = 0;
			for (int i = 0; i < 26; i++) can += (cnt[i] / d);
			if (can * d >= len) {
				printf ("%d\n", len);
				break;
			} 
		}	
	}
	re 0;
}