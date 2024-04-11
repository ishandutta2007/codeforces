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
char s[1000010];
char t[1000010];
int cs[26];
int ct[26];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		scanf (" %s", s);
		scanf (" %s", t);
		for (int i = 0; i < 26; i++) cs[i] = ct[i] = 0;
		for (int i = 0; i < n; i++) {
			cs[s[i] - 'a']++;
			ct[t[i] - 'a']++;
		}
		for (int i = 0; i < 25; i++)
			if (cs[i] > ct[i]) {
				int tmp = (cs[i] - ct[i] + m - 1) / m * m;
				cs[i] -= tmp;
				cs[i + 1] += tmp;
			}
		int ok = 1;
		for (int i = 0; i < 26; i++) ok &= int (cs[i] == ct[i]);
		printf ("%s\n", ok ? "Yes" : "No");
	}
	re 0;
}