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
string s[10];

int same (int i) {
	for (int j = 0; j < n; j++)
		if (i != j && s[i] == s[j])
			re 1;
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 0; it < tt; it++) {
		cin >> n;
		set<string> all;
		int ans = 0;
		for (int i = 0; i < n; i++) cin >> s[i];
		for (int i = 0; i < n; i++) {
			if (!same (i)) continue;
			ans++;
			int ok = 0;
			for (int j = 0; j < 4 && !ok; j++)
				for (int k = 0; k < 10 && !ok; k++) {
					s[i][j] = k + '0';
					if (!same (i)) ok = 1;
				}
		}
		printf ("%d\n", ans);
		for (int i = 0; i < n; i++) printf ("%s\n", s[i].c_str ());
	}
	re 0;
}