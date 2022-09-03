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
char h[100010];
int cnt[26];
int p[100010];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf (" %s", h); 
		n = strlen (h);
		memset (cnt, 0, sizeof (cnt));
		for (int i = 0; i < n; i++) cnt[h[i] - 'a']++;
		int one = -1, last = -1;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] == 1 && one == -1)
				one = i;
			if (cnt[i] > 0 && last == -1)
				last = i;
		}
		string res = "";
		if (cnt[last] == n) res = string (cnt[last], last + 'a'); else
		if (one != -1) {
			res += char (one + 'a');
			for (int i = 0; i < 26; i++)
				if (cnt[i] > 0 && i != one)
					res += string (cnt[i], i + 'a');
		} else {
			res += char (last + 'a');
//			printf ("%d %d\n", n - cnt[last], cnt[last] - 1);
			if ((n - cnt[last]) >= cnt[last] - 2) {
				cnt[last]--;
				for (int i = 0; sz (res) < n; ) {
					if (cnt[last] > 0) {
						res += char (last + 'a');
						cnt[last]--;
					}
					while (i < 26 && (i == last || cnt[i] == 0)) i++;
					if (i < 26) {
						res += char (i + 'a');
						cnt[i]--;
					}
				}
			} else {
				int last2 = last + 1;
				while (cnt[last2] == 0)	last2++;
				int rem = n - cnt[last] - cnt[last2];
				res += char (last2 + 'a');
				cnt[last]--;
				cnt[last2]--;
				if (rem == 0) {
					res += string (cnt[last2], last2 + 'a');
					res += string (cnt[last], last + 'a');
				} else {
					res += string (cnt[last], last + 'a');
					cnt[last] = 0;
					for (int i = 0; sz (res) < n; ) {
						while (i < 26 && (i == last || i == last2 || cnt[i] == 0)) i++;
						if (i < 26) {
							res += char (i + 'a');
							cnt[i]--;
							rem--;
						}
						if (cnt[last2] > 0) {
							res += string (cnt[last2], last2 + 'a');
							cnt[last2] = 0;
						}
					}
				}	
			}
		}
		printf ("%s\n", res.c_str ());
/*		int cur = 0;
		p[0] = -1;
		for (int i = 1; i < n; i++) {
			int k = p[i - 1];
			while (k >= 0 && res[k + 1] != res[i]) k = p[k];
			if (res[k + 1] == res[i]) k++;
			p[i] = k;
			cur = max (cur, k + 1);
		}
		printf ("%d\n", cur);
		for (int i = 0; i < n; i++) fprintf (stderr, "%d ", p[i] + 1);
		fprintf (stderr, "\n");*/
	}
    re 0;
}