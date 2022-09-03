#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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
char h[500010];
int cnt[26];
int bad[26];
int base[26];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf (" %s", h);
		n = strlen (h);
		memset (cnt, 0, sizeof (cnt));
		for (int i = 0; i < n; i++) cnt[h[i] - 'a']++;
		vi w;
		for (int i = 0; i < 26; i++)
			if (cnt[i])
				w.pb (i);
		memset (bad, 0, sizeof (bad));
		string res = "";
		int ok = 1;
		int sum = 0;
		for (int i = n - 1, j = 0; i >= 0; j++) {
			int k = i;
			while (k >= 0 && bad[h[k] - 'a']) k--;
			if (k < 0) {
				ok = 0;
				break;
			}
			res += h[k];
			int cur = h[k] - 'a';
			bad[cur] = 1;
			if (cnt[cur] % (sz (w) - j) != 0) {
				ok = 0;
				break;
			}
			base[cur] = (cnt[cur] / (sz (w) - j));
			sum += base[cur];
			if (i - sum + 1 < 0) {
				ok = 0;
				break;
			}
			for (int k = 0; k < sum; k++)
				if (!bad[h[i - k] - 'a']) {
					ok = 0;
					break;
				}
			if (!ok) break;
			i -= sum;
		}
		reverse (all (res));
		if (ok) {
			for (int i = 0, j = 0; i < sz (res); i++) {
				for (int k = 0; k < sum; k++)
					if (bad[h[k] - 'a']) {
						if (j >= n || h[j] != h[k]) {
							ok = 0;
							break;
						}
						j++;
					}
//				printf ("%d %d %d\n", i, j, ok);
				if (!ok) break;	
				bad[res[i] - 'a'] = 0;
			}
		}
		if (!ok) printf ("-1\n"); else {
			for (int i = 0; i < sum; i++) printf ("%c", h[i]);
			printf (" %s\n", res.c_str ());
		}	
	}
    re 0;
}