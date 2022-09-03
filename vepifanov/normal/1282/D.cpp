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
int cb[301];

int ask (const string& s) {
	if (s == "") re 300;
	printf ("%s\n", s.c_str ()); fflush (stdout);
	int x;
	scanf ("%d", &x);
	re x;
}

int main () {
	string s (300, 'a');
	int cur = ask (s);
	if (cur == 0) re 0;
	int ca = 300 - cur;
	s = string (ca, 'a');
	cur = ask (s);
	if (cur == 0) re 0;
	for (int i = 0; i <= ca; i++) cb[i] = 0;
	for (int i = 0; i <= ca; i++) {
		while (true) {
			cb[i]++;
			string t = "";
			for (int j = 0; j <= ca; j++) {
				t += string (cb[j], 'b');
				if (j < ca) t += "a";
			}
			int tmp = ask (t);
			if (tmp == 0) re 0;
			if (tmp >= cur) {
				cb[i]--;
				break;
			}
			cur = tmp;
		}
	}
	re 0;
}