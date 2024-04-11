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
int cnt[200001][26];
string s;

int main () {
	cin >> s;
	n = sz (s);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) cnt[i][j] = cnt[i + 1][j];
		cnt[i][s[i] - 'a']++;
	}
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf ("%d%d", &l, &r); l--; r--;
		int diff = 0;
		for (int j = 0; j < 26; j++)
			if (cnt[l][j] - cnt[r + 1][j] > 0)
				diff++;
		if (l == r || diff >= 3 || (diff == 2 && s[l] != s[r])) printf ("Yes\n"); else printf ("No\n");
	}
	re 0;
}