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
char s[100010];
string ans;

void get (int ai, int bi) {
	string c = "";
	int r = 0;
	for (int i = bi - 1, j = n - 1; i >= 0 || j >= bi; i--, j--) {
		int x = (i >= 0 ? s[i] - '0' : 0) + (j >= bi ? s[j] - '0' : 0) + r;
		r = x / 10;
		c = c + char ('0' + x % 10);
	}
	if (r) c += "1";
	reverse (all (c));
	if (ans == "" || (sz (c) < sz (ans) || (sz (c) == sz (ans) && c < ans))) ans = c;
}

int main () {
	scanf ("%d %s", &n, s);
	int len = 1e9;
	for (int i = 1; i < n; i++)
		if (s[i] != '0')
			len = min (len, max (i, n - i));
	ans = "";
	for (int i = 1; i < n; i++)
		if (s[i] != '0' && max (i, n - i) <= len + 1)
			get (0, i);
	printf ("%s\n", ans.c_str ());
	re 0;
}