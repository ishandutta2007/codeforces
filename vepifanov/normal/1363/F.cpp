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

const int mod1 = 1000*1000*1000+7;
const int mod2 = 1000*1000*1000+9;

int n;
char s[2010];
char t[2010];
//int res[2010][2010];
map<pair<int, ll>, int> res[2010];
vi cnt;
int ph1[26];
int ph2[26];

int go (int i, int j, int ch1, int ch2) {
//	printf ("%d %d\n", i, j);
	if (j < 0) re 0;

	if (ch1 < 0) ch1 += mod1; else
	if (ch1 >= mod1) ch1 -= mod1;

	if (ch2 < 0) ch2 += mod2; else
	if (ch2 >= mod2) ch2 -= mod2;

	ll ch = ((ll)ch1 * mod2 + ch2);

	if (res[i + 1].count (mp (j, ch))) re res[i + 1][mp (j, ch)];
	int cur = 1e9;
	if (i >= 0 && s[i] == t[j]) { cur = go (i - 1, j - 1, ch1, ch2); } else {
		if (cnt[t[j] - 'a'] > 0) {
			cnt[t[j] - 'a']--;
			cur = min (cur, go (i, j - 1, ch1 - ph1[t[j] - 'a'], ch2 - ph2[t[j] - 'a']));
			cnt[t[j] - 'a']++;
		}
		if (i >= 0) {
			cnt[s[i] - 'a']++;
			cur = min (cur, go (i - 1, j, ch1 + ph1[s[i] - 'a'], ch2 + ph2[s[i] - 'a']) + 1);
			cnt[s[i] - 'a']--;
		}
	}
//	printf ("%d %d = %d\n", i, j, cur);
	re res[i + 1][mp (j, ch)] = cur;
}

int main () {
	ph1[0] = ph2[0] = 1;
	for (int i = 1; i < 26; i++) {
		ph1[i] = ((ll)ph1[i - 1] * 17239) % mod1;
		ph2[i] = ((ll)ph2[i - 1] * 23917) % mod2;
	}
	cnt.resize (26);
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		scanf (" %s %s", s, t);
		for (int i = 0; i < 26; i++) cnt[i] = 0;
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
			cnt[t[i] - 'a']--;
		}
		int ok = 1;
		for (int i = 0; i < 26; i++) ok &= int (cnt[i] == 0);
		if (ok) {
			for (int i = 0; i <= n; i++) res[i].clear ();
			printf ("%d\n", go (n - 1, n - 1, 0, 0));
			for (int i = 0; i <= n; i++) res[i].clear ();
		} else printf ("-1\n");
	}
	re 0;
}